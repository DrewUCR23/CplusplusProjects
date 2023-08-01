/*  Drew Gonzales
 * 4/23/2023
 * Professor Mark lehr 
 * INDIVIDUAL PROJECT 
 * 
 * OBJECTIVE: The objective of this project would be to create a basic time tracker that will keep track of the time of a user and then read the given number of sessions
 * accordingly 
 */
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include "USER.h"
#include "ADMIN.h"
#include "Common.h"

using namespace std;
void timetracker(bool& loggedIn, std::chrono::duration<double>& totalTime) {
    auto startTime = std::chrono::system_clock::now();

    while (loggedIn) {
        auto currentTime = std::chrono::system_clock::now();
        totalTime = std::chrono::duration_cast<std::chrono::duration<double>>(currentTime - startTime);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
int main(int argc, char** argv) {
    int choice;
    std::string USERNAME, PASSWORD, ADMINP;
    bool loggedIn = false;
    std::chrono::duration<double> totalTime(0);
    User user;
    Admin admin;
    bool  ADMINACTION = false;  
    std::cout << "Welcome to Drew's Time Tracker" << std::endl;

    const std::string userFilename = "users.bin";

    while (!choice == 0) {
        std::cout << "Time Tracker Menu" << std::endl;
        std::cout << "1. Sign in as User" << std::endl;
        std::cout << "2. Sign in as Admin" << std::endl;
        std::cout << "3. Change a user's password" << std::endl;
        std::cout << "4. Create an Admin account" << std::endl;
        std::cout << "5. Create a User account" << std::endl;
        std::cout << "6. Delete a User Record or View a user Record" << std::endl;
        std::cout << "0. Logout" << std::endl;
        std::cout << "Enter a choice shown above: ";
        std::cin >> choice;
        switch (choice) {
            case 0:
                // Logout
        if (loggedIn) {
            loggedIn = false;
            std::cout << "Logged out successfully." << std::endl;
            std::cout << "Total time logged in: " << totalTime.count() << " seconds" << std::endl;
            totalTime = std::chrono::duration<double>(0);
                } else {
                    std::cout << "You must be logged in to log out." << std::endl;
                }
                break;
            case 1:
                // Sign in as User
                if (!loggedIn) {
                    std::cout << "Enter username: ";
                    std::cin >> std::ws; // Add this line to clear any whitespaces from the input buffer
                    std::getline(std::cin, USERNAME);
                    std::cout << "Enter password: ";
                    std::getline(std::cin, PASSWORD);

                    if (user.loadUser(userFilename, USERNAME, PASSWORD)) {
                        if (user.getUserStatus()) {
                            loggedIn = true;
                            std::cout << "User signed in successfully!" << std::endl;
                            std::thread timerThread(timetracker, std::ref(loggedIn), std::ref(totalTime));
                            timerThread.detach();
                        } else {
                            std::cout << "Invalid user credentials." << std::endl;
                        }
                    } else {
                        std::cout << "Invalid username or password." << std::endl;
                    }
                }
                break;

            case 2: // Sign in as Admin
                if (!loggedIn) {
                    std::cout << "Enter username: ";
                    std::cin >> USERNAME;
                    std::cout << "Enter password: ";
                    std::cin >> PASSWORD;

                    if (admin.loadAdmin(userFilename)) {
                        std::fstream file(userFilename, std::ios::in | std::ios::binary);
                        if (file.is_open()) {
                            file.read(reinterpret_cast<char*> (&admin), sizeof (admin));
                            std::cout << "The file is now open." << std::endl;
                        } else {
                            std::cout << "Failed to open file." << std::endl;
                        }
                        if (admin.getUserStatus()) {
                            loggedIn = true;
                            std::cout << "Admin signed in successfully!" << std::endl;
                            std::thread timerThread(timetracker, std::ref(loggedIn), std::ref(totalTime));
                            timerThread.detach();
                        } else {
                            std::cout << "Invalid admin credentials." << std::endl;
                        }
                    } else {
                        std::cout << "Invalid username or password." << std::endl;
                    }
                }
                break;

            case 3:
                // Change a user's password
                if (loggedIn) {
                    std::string newPassword;
                    std::cout << "Enter old password: ";
                    std::cin >> PASSWORD;
                    std::cout << "Enter new password: ";
                    std::cin >> newPassword;
                    user.changePassword(PASSWORD, newPassword);
                } else {
                    std::cout << "You must be logged in to change your password." << std::endl;
                }
                break;
            case 4:
                // Create an Admin account
                if (!loggedIn) {
                    std::cout << "Enter admin username: ";
                    std::cin >> USERNAME;
                    std::cout << "Enter admin password: ";
                    std::cin >> PASSWORD;

                    admin.createAdminAccount(userFilename, USERNAME, PASSWORD);
                    std::cout << "Admin account created successfully!" << std::endl;
                } else {
                    std::cout << "You must be logged out to create an admin account." << std::endl;
                }
                break;
            case 5:
                cout << "Enter a USERNAME for new account: ";
                cin >> USERNAME;
                cout << "Enter a password for new account: ";
                cin >> PASSWORD;

                user.setUser(USERNAME, PASSWORD);
                user.createUser(userFilename, USERNAME,PASSWORD);
                break
            case 6:
                std::cout << "You must be signed in as an admin in order to manage user accounts" << std::endl;
                std::cout << "Enter VIEW ACCOUNT, VIEW ALL RECORDS, DELETE ACCOUNT or DONE to terminate ADMIN RESPONSIBILITIES" << std::endl;

                if (loggedIn && admin.getUserStatus()) {
                    std::string adminInput;
                    std::cin.ignore();
                    while (adminInput != "DONE") {
                        std::getline(std::cin, adminInput);
                        if (adminInput == "VIEW ACCOUNT") {
                            std::cout << "Enter the username of the account to view: ";
                            std::getline(std::cin, USERNAME);
                            UserInfo userInfo;
                            bool found = false;
                            std::ifstream file(userFilename, std::ios::in | std::ios::binary);
                            while (file.read(reinterpret_cast<char*> (&userInfo), sizeof (userInfo))) {
                                if (USERNAME == userInfo.username) {
                        found = true;
                        std::cout << "Username: " << userInfo.username << ", Password: " << userInfo.password << std::endl;
                        break;
                    }
                }
                file.close();
                if (!found) {
                    std::cout << "User not found." << std::endl;
                }
            } else if (adminInput == "VIEW ALL RECORDS") {
                UserInfo userInfo;
                std::ifstream file(userFilename, std::ios::in | std::ios::binary);
                while (file.read(reinterpret_cast<char*>(&userInfo), sizeof(userInfo))) {
                    std::cout << "Username: " << userInfo.username << ", Password: " << userInfo.password << std::endl;
                }
                file.close();
            } else if (adminInput == "DELETE ACCOUNT") {
                std::cout << "Enter the username of the account to delete: ";
                std::getline(std::cin, USERNAME);
                std::vector<UserInfo> users;
                UserInfo userInfo;
                bool found = false;
                std::ifstream inFile(userFilename, std::ios::in | std::ios::binary);
                while (inFile.read(reinterpret_cast<char*>(&userInfo), sizeof(userInfo))) {
                    if (USERNAME != userInfo.username) {
                        users.push_back(userInfo);
                    } else {
                        found = true;
                    }
                }
                inFile.close();

                if (found) {
                    std::ofstream outFile(userFilename, std::ios::out | std::ios::binary);
                    for (const UserInfo& user : users) {
                        outFile.write(reinterpret_cast<const char*>(&user), sizeof(user));
                    }
                    outFile.close();
                    std::cout << "User account deleted." << std::endl;
                } else {
                    std::cout << "User not found." << std::endl;
                }
            } else if (adminInput == "DONE") {
                std::cout << "Terminating admin responsibilities..." << std::endl;
            } else {
                std::cout << "You've entered an invalid response. Please try again." << std::endl;
            }
        }
    } else {
        std::cout << "You are an invalid user or not logged in as an admin. Please try again." << std::endl;
    }
    break;


    }
}
    return 0;
}
