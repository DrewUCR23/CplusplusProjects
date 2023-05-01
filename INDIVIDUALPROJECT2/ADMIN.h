#ifndef ADMIN_H
#define ADMIN_H

#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include "definition.h"
#include "INSTOCK.h"
#include "USER.h"

class Admin {
private:
    struct AdminInfo {
        char username[50];
        char password[50];
        bool status;
    };
    AdminInfo info;

    void loadAdmin(const std::string& filename) {
        std::ifstream file(filename, std::ios::binary);
        if (file.is_open()) {
            AdminInfo temp;
            while (file.read(reinterpret_cast<char*>(&temp), sizeof(AdminInfo))) {
                if (temp.status) {
                    info = temp;
                    break;
                }
            }
            file.close();
        } else {
            std::cerr << "Unable to open file: " << filename << std::endl;
        }
    }

public:

    Admin(const std::string& filename) {
        loadAdmin(filename);
    }

    
    //the header file will account for and removes a duplicate message that might occur 
  void setUser(const std::string& user, const std::string& password) {
    std::strcpy(info.username, user.c_str());
    std::strcpy(info.password, password.c_str());

    validateUser();

    if (info.status) {
        std::cout << "Admin : " << info.username << std::endl;
    } else {
        std::cout << "Invalid admin credentials." << std::endl;
    }
}


    void createAdminAccount(const std::string& username, const std::string& password) {
        std::strcpy(info.username, username.c_str());
        std::strcpy(info.password, password.c_str());
        info.status = true;

        std::ofstream file("admin.bin", std::ios::binary | std::ios::trunc);
        if (file.is_open()) {
            file.write(reinterpret_cast<char*>(&info), sizeof(AdminInfo));
            file.close();
            std::cout << "Admin account created successfully!" << std::endl;
        } else {
            std::cerr << "Unable to open file: admin.bin" << std::endl;
        }
    }

    void validateUser() {
        // Example validation logic
        if (std::strcmp(info.username, "admin") == 0 && std::strcmp(info.password, "admin_password") == 0) {
            info.status = true;
        } else {
            info.status = false;
        }
    }

    bool getUserStatus() {
        return info.status;
    }

    void queryPurchases() {
        // Check if the admin is logged in
        if (getUserStatus()) {
            std::cout << "Purchase records:\n";
            std::ifstream infile("purchase_records.bin", std::ios::binary);
            if (infile.is_open()) {
                std::string food_name;
                int quantity;
                float price, totalPrice, pricePaid, change;
                while (true) {
                    // Read food name
                    std::getline(infile, food_name, '\0');
                    if (infile.eof()) break;
                    infile.read(reinterpret_cast<char*>(&price), sizeof(price));
                    infile.read(reinterpret_cast<char*> (&quantity), sizeof (quantity));

                    std::cout << "Food Name: " << food_name << ", Quantity: " << quantity
                            << ", Price: " << price << std::endl;
                }

                infile.read(reinterpret_cast<char*> (&totalPrice), sizeof (totalPrice));
                infile.read(reinterpret_cast<char*> (&pricePaid), sizeof (pricePaid));
                infile.read(reinterpret_cast<char*> (&change), sizeof (change));

                std::cout << "Total Price: " << totalPrice << ", Price Paid: " << pricePaid << ", Change: " << change << std::endl;

                infile.close();
            } else {
                std::cerr << "Failed to open file : purchase_records.bin" << std::endl;
            }
        } else {
            std::cout << "Access denied. Admin not logged in." << std::endl;
        }
    }
};
#endif // ADMIN_H

