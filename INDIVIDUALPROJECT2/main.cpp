/* 
 Drew Gonzales
 Personal Project 2
 Professor Mark Lehr
 * CIS-17B 
 * STORE FRONT 2 
 *
 * OBJECTIVE: In this project I will write the basic implementation for the store front, this will show various types of foods that are available
 * it will also have admin and user accounts that you can use to log in in order to buy various types of food for yourself at a later period time. Furthermore,
 * for this lab I will make a shopping cart that allows the admin to query info for relevant purchases, accounts that are active and available info and more. 
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
#include "USER.h"
#include "ADMIN.h"
#include "definition.h"
#include "INSTOCK.h"
using namespace std;

int main() {
    string CHOICE, USERNAME, PASSWORD, USERFILENAME = "ACCOUNTDATABASE.bin", USERCHOICE;
    int USERQUANTITY, HOWMUCHPAID, USERNUMBER;
    bool loggedIn = false;
    User user;
    Admin admin(USERFILENAME);
    FOODINVENTORY world;
    FOODNAMES foodNames;
    string newPassword;
    string ADMINCHOICE1;
    int NUMBERTEST;
    //Admin queryAdmin(USERFILENAME); // Pass the binary filename to the Admin constructor
    float total_price = 0;
    int leftover = 0;
    map<string, int> user_choices;
    vector<Food> purchases;

    cout << "---------------------------DREW's Online Grocery Store-----------------------" << endl;
    cout << "Type FINISHED to stop shopping or type CHECK CART to see what you've picked" << endl;
    cout << "The system ADMIN may be able to access all stored receipts as they are in a BIN file." << endl;
    cout << "The ADMIN can delete delete records by entering DELETE or ADD record by adding ADD" << endl;

    while (USERNUMBER != 0) {
        cout << "Drew's Login MENU" << endl;
        cout << "1. Login as a user to shop" << endl;
        cout << "2. Make a new user account" << endl;
        cout << "3. Change your user Password" << endl;
        cout << "4. Create an Admin Account" << endl;
        cout << "5. To check The Store Menu" << endl;
        cout << "6. Check to see the stored Purchases as an ADMIN:" << endl;
        cout << "7. To check the items you have in your cart" << endl;
        cout << "8. To start your online shopping(YOU MUST BE LOGGED IN)" << endl;
        cout << "9. Choose if you want to print out your Receipt:" << endl;
        cout << "10. If you want to delete a purchase from a file or a user" << endl;
        cout << "0. So you can Log out Accordingly" << endl;
        cout << "Enter an option: ";
        cin >> USERNUMBER;

        switch (USERNUMBER) {
            case 1:
                cout << "Enter a USERNAME: ";
                cin >> USERNAME;
                cout << "Enter a password: ";
                cin >> PASSWORD;

                if (user.loadUser(USERFILENAME, USERNAME, PASSWORD)) {
                    loggedIn = true;
                    cout << "Logged in successfully!" << endl;
                } else {
                    cout << "Invalid username or password. Please try again." << endl;
                }
                break;
            case 2:
                cout << "Enter a USERNAME for new account: ";
                cin >> USERNAME;
                cout << "Enter a password for new account: ";
                cin >> PASSWORD;

                user.setUser(USERNAME, PASSWORD);
                user.createUser(USERFILENAME);
                break;
            case 3:
                cout << "Enter your current password: ";
                cin >> PASSWORD;
                cout << "Enter your new password: ";
                cin >> newPassword;
                user.changePassword(PASSWORD, newPassword);
                break;
            case 4:
                cout << "Enter a USERNAME for new admin account: ";
                cin >> USERNAME;
                cout << "Enter a password for new admin account: ";
                cin >> PASSWORD;

                admin.setUser(USERNAME, PASSWORD);
                admin.createAdminAccount(USERNAME, PASSWORD);
                break;
            case 5:
                // show the names of the foods in stock, costs and given quantities 
                FOODSTOCK(world, foodNames);
                break;
            case 6:
                cout << "Enter ADMIN username: ";
                cin >> USERNAME;
                cout << "Enter ADMIN password: ";
                cin >> PASSWORD;

                admin.setUser(USERNAME, PASSWORD);
                //validate the user has logged in once loggin credentials are entered
                if (admin.getUserStatus()) {
                    cout << "Admin logged in successfully." << endl;
                } else {
                    cout << "Invalid admin credentials." << endl;
                }
                //calls the query into the main cpp
                if (admin.getUserStatus()) {
                    admin.queryPurchases();
                } else {
                    cout << "Access denied. Please log in as an admin to view purchase records." << endl;
                }
                break;


            case 7:
                LOADSHOPPINGCART(world, foodNames, user_choices);
                break;
            case 8:
                if (loggedIn == true) {
                    FOODSTOCK(world, foodNames);
                    while (CHOICE != "FINISHED") {
                        cout << "Remember to HIT FINISHED! when you're done shopping to go to the checkout" << endl;
                        cout << "Pick a choice and enter it below" << endl;
                        cin >> CHOICE;

                        if (CHOICE == "FINISHED") {
                            break;
                        }

                        cout << "How many of this given food option do you want?" << endl;
                        cin >> USERQUANTITY;

                        // Add the user's choice and quantity to the user_choices map
                        user_choices[CHOICE] = USERQUANTITY;

                        cout << "How much do you want to pay today" << endl;
                        cin >> HOWMUCHPAID;

                        // Load the shopping cart to display the items
                        LOADSHOPPINGCART(world, foodNames, user_choices);
                    }
                } else {
                    cout << "You need to be logged into an account to buy food. Try again" << endl;
                }
                break;

            case 9:
                // Output the receipt of what has been purchased 
                RECEIPT(world, foodNames, user_choices, HOWMUCHPAID);
                // Call the STOREPURCHASES function to store the purchases

                STOREPURCHASES(foodNames, user_choices, HOWMUCHPAID, total_price, leftover); // Update the STOREPURCHASES function call
                break;
            case 10:
                cout << "Enter DONE to finish ADMIN duties" << endl;
                cout << "Please login first" << endl;
                cout << "Enter ADMIN username: ";
                cin >> USERNAME;
                cout << "Enter ADMIN password: ";
                cin >> PASSWORD;
                cin.ignore();

                if (admin.getUserStatus()) {
                    bool loggedIn = true;
                    std::ifstream file("admin.bin", std::ios::binary);
                    while (ADMINCHOICE1 != "DONE") {
                        cout << "You can choose VIEW ACCOUNTS, VIEW PURCHASES, DELETE USER RECORD, or DELETE PURCHASES RECORD" << endl;
                        std::getline(std::cin, ADMINCHOICE1);

                        if (ADMINCHOICE1 == "VIEW ACCOUNTS") {
                            cin.ignore();
                            std::ifstream file(USERFILENAME, std::ios::binary);
                            if (file.is_open()) {
                                User::UserInfo temp;
                                while (file.read(reinterpret_cast<char*> (&temp), sizeof (User::UserInfo))) {
                                    if (temp.status) {
                                        std::cout << "Username: " << temp.username << ", Is admin: " << temp.isAdmin << std::endl;
                                    }
                                }
                                file.close();
                            } else {
                                std::cerr << "Unable to open file: " << USERFILENAME << std::endl;
                            }
                        } else if (ADMINCHOICE1 == "VIEW PURCHASES") {
                            cin.ignore();
                            std::ifstream file("purchase_records.bin", std::ios::binary);
                            if (file.is_open()) {
                                std::string food_name;
                                int quantity;
                                float price, totalPrice, pricePaid, change;
                                while (true) {
                                    std::getline(file, food_name, '\0');
                                    if (file.eof()) break;
                                    file.read(reinterpret_cast<char*> (&price), sizeof (price));
                                    file.read(reinterpret_cast<char*> (&quantity), sizeof (quantity));

                                    std::cout << "Food Name: " << food_name << ", Quantity: " << quantity
                                            << ", Price: " << price << std::endl;
                                }

                                file.read(reinterpret_cast<char*> (&totalPrice), sizeof (totalPrice));
                                file.read(reinterpret_cast<char*> (&pricePaid), sizeof (pricePaid));
                                file.read(reinterpret_cast<char*> (&change), sizeof (change));

                                std::cout << "Total Price: " << totalPrice << ", Price Paid: " << pricePaid << ", Change: " << change << std::endl;

                                file.close();
                            } else {
                                std::cerr << "Failed to open file: purchase_records.bin" << std::endl;
                            }
                        } else if (ADMINCHOICE1 == "DELETE USER") {
                            cin.ignore();
                            std::string targetUsername;
                            cout << "Enter the username of the user you want to delete: ";
                            std::getline(std::cin, targetUsername);

                            std::ifstream inputFile(USERFILENAME, std::ios::binary);
                            std::ofstream tempFile("temp_user_records.bin", std::ios::binary);

                            if (inputFile.is_open() && tempFile.is_open()) {
                                User::UserInfo temp;
                                bool found = false;
                                while (inputFile.read(reinterpret_cast<char*> (&temp), sizeof (User::UserInfo))) {
                                    if (temp.status && temp.username != targetUsername) {
                                        tempFile.write(reinterpret_cast<const char*> (&temp), sizeof (User::UserInfo));
                                    } else if (temp.status && temp.username == targetUsername) {
                                        found = true;
                                    }
                                }

                                inputFile.close();
                                tempFile.close();

                                inputFile.open(USERFILENAME, std::ios::out | std::ios::binary);
                                tempFile.open("temp_user_records.bin", std::ios::in | std::ios::binary);
                                if (inputFile.is_open() && tempFile.is_open()) {
                                    char buffer[4096];
                                    std::size_t bytesRead;

                                    while ((bytesRead = inputFile.read(buffer, sizeof (buffer)).gcount()) > 0) {
                                        tempFile.write(buffer, bytesRead);
                                    }


                                    inputFile.close();
                                    tempFile.close();
                                } else {
                                    std::cerr << "Unable to open files." << std::endl;
                                }

                                std::remove("temp_user_records.bin");

                                if (found) {
                                    cout << "User record deleted successfully." << endl;
                                } else {
                                    cout << "User record not found." << endl;
                                }
                            } else {
                                std::cerr << "Unable to open files." << std::endl;
                            }
                        } else if (ADMINCHOICE1 == "DELETE PURCHASE") {
                            cin.ignore();
                            std::string targetFoodName;
                            cout << "Enter the food name of the purchase you want to delete: ";
                            std::getline(std::cin, targetFoodName);

                            std::ifstream inputFile("purchase_records.bin", std::ios::binary);
                            std::ofstream tempFile("purchase_records1.bin", std::ios::binary);

                            if (inputFile.is_open() && tempFile.is_open()) {
                                std::string food_name;
                                int quantity;
                                float price;
                                bool found = false;

                                while (true) {
                                    std::getline(inputFile, food_name, '\0');
                                    if (inputFile.eof()) break;
                                    inputFile.read(reinterpret_cast<char*> (&price), sizeof (price));
                                    inputFile.read(reinterpret_cast<char*> (&quantity), sizeof (quantity));

                                    if (food_name != targetFoodName) {
                                        tempFile.write(food_name.c_str(), food_name.length());
                                        tempFile.put('\0');
                                        tempFile.write(reinterpret_cast<const char*> (&price), sizeof (price));
                                        tempFile.write(reinterpret_cast<const char*> (&quantity), sizeof (quantity));
                                    } else {
                                        found = true;
                                    }
                                }

                                inputFile.close();
                                tempFile.close();
                                std::remove("purchase_records.bin");
                                std::rename("purchase_records1.bin", "purchase_records.bin");

                                if (found) {
                                    cout << "Purchase record deleted successfully." << endl;
                                } else {
                                    cout << "Purchase record not found." << endl;
                                }
                            } else {
                                std::cerr << "Unable to open files." << std::endl;
                            }
                        }
                    }
                } else {
                    cout << "Invalid admin credentials." << endl;
                }
                break;
                case 0:
             loggedIn = false;
                cout << "Logged out successfully!" << endl;
                break;
                default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    }
            return 0;
    }


