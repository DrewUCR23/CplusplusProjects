#ifndef USER_H
#define USER_H

#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include "Common.h"

class User {
private:
    UserInfo info;

public:
    User() {
        std::strcpy(info.username, " ");
        std::strcpy(info.password, " ");
    }

    void setUser(const std::string& user, const std::string& password) {
        std::strcpy(info.username, user.c_str());
        std::strcpy(info.password, password.c_str());
    }

    bool getUserStatus() const {
        return strlen(info.username) > 0 && strlen(info.password) > 0;
    }

    bool loadUser(const std::string& userFilename, const std::string& username, const std::string& password) {
        std::ifstream file(userFilename, std::ios::in | std::ios::binary);
        UserInfo temp;

        if (!file.is_open()) {
            return false;
        }

        while (file.read(reinterpret_cast<char*>(&temp), sizeof(temp))) {
            if (username == temp.username && password == temp.password) {
                info = temp;
                file.close();
                return true;
            }
        }

        file.close();
        return false;
    }

    void changePassword(const std::string& oldPassword, const std::string& newPassword) {
        if (oldPassword == info.password) {
            std::strcpy(info.password, newPassword.c_str());
            std::cout << "Password changed successfully!" << std::endl;
        } else {
            std::cout << "Incorrect old password." << std::endl;
        }
    }

    void createUser(const std::string& userFilename, const std::string& username, const std::string& password) {
        UserInfo newUser;
        std::strcpy(newUser.username, username.c_str());
        std::strcpy(newUser.password, password.c_str());
        std::ofstream file(userFilename, std::ios::app | std::ios::binary);
        file.write(reinterpret_cast<char*>(&newUser), sizeof(newUser));
        file.close();
    }
};

#endif /* USER_H */
