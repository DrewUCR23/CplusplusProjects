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
    string USERNAME, PASSWORD, ADMINP;
    bool loggedIn = false;
    std::chrono::duration<double> totalTime(0);
    User user;
    UserInfo& info = UserInfoAccessor::getInfo(user);
    Admin admin;
    std::cout << "Welcome to Drew's Time Tracker" << std::endl;

    const std::string userFilename = "users.bin";

    while (true) {
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
            case 1:
                // Sign in as User
                if (!loggedIn) {
                    std::cout << "Enter username: ";
                    std::cin >> USERNAME;
                    std::cout << "Enter password: ";
                    std::cin >> PASSWORD;

                    if (user.loadUser(userFilename, USERNAME, PASSWORD)) {
                        std::fstream file("users.bin", std::ios::in | std::ios::binary);
                        if (file.is_open()) {
                            file.read(reinterpret_cast<char*> (&user), sizeof (user));
                            std::cout << "The file is now open." << std::endl;
                        } else {
                            std::cout << "Failed to open file." << std::endl;
                        }
                        if (user.isUserValid()) {
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
                break;
            case 2:
                // Sign in as Admin
                if (!loggedIn) {
                    std::cout << "Enter admin username: ";
                    std::cin >> USERNAME;
                    std::cout << "Enter admin password: ";
                    std::cin >> PASSWORD;
                    admin.setUser(USERNAME, PASSWORD);
                    loggedIn = admin.getUserStatus();
                    if (loggedIn) {
                        std::thread timerThread(timetracker, std::ref(loggedIn), std::ref(totalTime));
                        timerThread.detach();
                    }
                }
                break;

            case 3:
                if (loggedIn) {
                    std::string oldPassword, newPassword;
                    std::cout << "Enter your old password: ";
                    std::cin >> oldPassword;
                    std::cout << "Enter your new password: ";
                    std::cin >> newPassword;
                    user.changePassword(oldPassword, newPassword);
                } else {
                    std::cout << "Please log in to change your password." << std::endl;
                }
                break;

            case 4:
                // Create an Admin account
                if (loggedIn) {
                    std::cout << "Only admins can create new admin accounts." << std::endl;
                } else {
                    std::string newAdminUsername, newAdminPassword;
                    std::cout << "Enter the new admin username: ";
                    std::cin >> newAdminUsername;
                    std::cout << "Enter the new admin password: ";
                    std::cin >> newAdminPassword;
                    admin.createAdminAccount(newAdminUsername, newAdminPassword);
                }
                break;
            case 5:
                // Create a User account
                if (loggedIn) {
                    std::cout << "Please log out before creating a new user account." << std::endl;
                } else {
                    std::string newUserUsername, newUserPassword;
                    std::cout << "Enter the new user's username: ";
                    std::cin >> newUserUsername;
                    std::cout << "Enter the new user's password: ";
                    std::cin >> newUserPassword;
                    user.setUser(newUserUsername, newUserPassword);
                    user.createUser(userFilename);
                }
                break;
            case 6:
                if (loggedIn) {
                    admin.setUser(USERNAME, PASSWORD);
                    loggedIn = admin.getUserStatus();
                    if (loggedIn && admin.info.isAdmin) {
                        std::cout << "Enter VIEW ACCOUNT or DELETE ACCOUNT to view/delete user records" << std::endl;
                        std::cout << "Enter Done to finish admin tasks" << std::endl;
                        std::string adminChoice;
                        std::cin >> adminChoice;
                        while (adminChoice != "Done") {
                            if (adminChoice == "VIEW ACCOUNT") {
                                std::ifstream file("users.bin", std::ios::binary);
                                if (file.is_open()) {
                                    value values;
                                    while (file.read(reinterpret_cast<char*> (&values.data), sizeof (UserInfo))) {
                                        User user;
                                        user.info = values.data;
                                        if (user.getUserStatus()) {
                                            std::cout << "Username: " << user.getUsername() << ", Is admin: " << UserInfoAccessor::getInfo(user).isAdmin << std::endl;
                                        }
                                    }
                                    file.close();
                                } else {
                                    std::cerr << "Unable to open file: users.bin" << std::endl;
                                }
                            } else if (adminChoice == "DELETE ACCOUNT") {
                                std::string username;
                                std::cout << "Enter the username of the account you want to delete: ";
                                std::cin >> username;
                                if (std::remove((username + ".bin").c_str()) != 0) {
                                    std::cerr << "Error deleting file" << std::endl;
                                } else {
                                    std::cout << "File successfully deleted" << std::endl;
                                }
                            } else {
                                std::cout << "Invalid selection. Please try again." << std::endl;
                            }
                            std::cin >> adminChoice;
                        }
                    } else {
                        std::cout << "You are not logged in as ADMIN. Try again!" << std::endl;
                    }
                } else {
                    std::cout << "You are not logged in. Please log in first." << std::endl;
                }
                break;


            case 0:
                // Logout
                loggedIn = false;
                std::cout << "You have logged out. Total time spent: " << totalTime.count() << " seconds." << std::endl;
                break;

            default:
                std::cout << "Invalid choice, please try again." << std::endl;
                break;
        }
    }

    return 0;
}
