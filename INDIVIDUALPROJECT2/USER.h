#ifndef USER_H
#define USER_H

#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include "definition.h"
#include "INSTOCK.h"
#include "ADMIN.h"

class User {
public:
    struct UserInfo {
        char username[50];
        char password[50];
        bool status;
        bool isAdmin; // Add this line
    };
    UserInfo info;
public:
       friend class Admin; // Add this line
    User() {
        std::strcpy(info.username, " ");
        std::strcpy(info.password, " ");
        info.status = false;
        info.isAdmin = false; // Add this line
    }

    void setUser(const std::string& user, const std::string& password) {
        std::strcpy(info.username, user.c_str());
        std::strcpy(info.password, password.c_str());
        info.status = true;

        std::cout << "User : " << info.username << std::endl;
    }

    void createUser(const std::string& filename, bool admin = false) {
        std::ofstream file(filename, std::ios::binary | std::ios::app);
        if (file.is_open()) {
            info.isAdmin = admin; // Set the isAdmin member
            file.write(reinterpret_cast<char*>(&info), sizeof(UserInfo));
            file.close();
            std::cout << "User account created successfully!" << std::endl;
        } else {
            std::cerr << "Unable to open file: " << filename << std::endl;
        }
    }

    bool loadUser(const std::string& filename, const std::string& username, const std::string& password) {
        std::ifstream file(filename, std::ios::binary);
        if (file.is_open()) {
            UserInfo temp;
            while (file.read(reinterpret_cast<char*>(&temp), sizeof(UserInfo))) {
                if (username == temp.username && password == temp.password) {
                    info = temp;
                    info.status = true;
                    return true;
                }
            }
            file.close();
        } else {
            std::cerr << "Unable to open file: " << filename << std::endl;
        }
        return false;
    }

    void changePassword(const std::string& oldPassword, const std::string& newPassword) {
        if (isLoggedIn() && oldPassword == std::string(info.password)) {
            std::strcpy(info.password, newPassword.c_str());
            std::cout << "Password changed successfully!" << std::endl;
        } else {
            std::cout << "Incorrect old password or not logged in. Password not changed." << std::endl;
        }
    }

    bool getUserStatus() {
        return info.status;
    }

    bool isLoggedIn() {
        return info.status;
    }

    bool getIsAdmin() const { // Add this function
        return info.isAdmin;
    }
};

#endif


