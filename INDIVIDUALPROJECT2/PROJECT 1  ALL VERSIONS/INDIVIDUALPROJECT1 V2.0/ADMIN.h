#ifndef ADMIN_H
#define ADMIN_H

#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include "Common.h"

class Admin {
private:
    UserInfo info;

public:

    Admin() {
        std::strcpy(info.username, "admin");
        std::strcpy(info.password, "admin_password");
        info.status = true;
    }

    void setUser(const std::string& user, const std::string& password) {
        std::strcpy(info.username, user.c_str());
        std::strcpy(info.password, password.c_str());
        info.status = true;

        validateUser();

        std::cout << "Admin : " << info.username << std::endl;
    }

    void createAdminAccount(const std::string& username, const std::string& password) {
        std::strcpy(info.username, username.c_str());
        std::strcpy(info.password, password.c_str());
        info.status = true;

        std::cout << "Admin account created successfully!" << std::endl;
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

};

#endif /* ADMIN_H */
