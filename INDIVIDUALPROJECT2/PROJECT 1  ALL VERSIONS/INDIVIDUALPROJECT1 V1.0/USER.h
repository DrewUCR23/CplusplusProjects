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
        info.status = true;
    }

    void setUser(const std::string& user, const std::string& password) {
        std::strcpy(info.username, user.c_str());
        std::strcpy(info.password, password.c_str());
        info.status = true;

        // Removed the call to validateUser()
        std::cout << "User : " << info.username << std::endl;
    }

    void createUser(const std::string& filename) {
        std::ofstream file(filename, std::ios::binary | std::ios::app);
        if (file.is_open()) {
            file.write(reinterpret_cast<char*> (&info), sizeof(UserInfo));
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
            while (file.read(reinterpret_cast<char*> (&temp), sizeof (UserInfo))) {
                if (username == temp.username && password == temp.password) {
                    info = temp;
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
        if (oldPassword == std::string(info.password)) {
            std::strcpy(info.password, newPassword.c_str());
            std::cout << "Password changed successfully!" << std::endl;
        } else {
            std::cout << "Incorrect old password. Password not changed." << std::endl;
        }
    }
    // Added a new isUserValid function
    bool isUserValid() const {
        // Add your validation logic here
        if (std::strcmp(info.username, "valid user") == 0 && std::strcmp(info.password, "valid password") == 0) {
            return true;
        } else {
            return false;
        }
    }

    bool getUserStatus() {
        return info.status;
    }

};

#endif /* USER_H */
