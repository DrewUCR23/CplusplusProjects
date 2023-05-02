#ifndef ADMIN_H
#define ADMIN_H

#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include "Common.h"

class Admin {
private:

    struct AdminInfo {
        char username[50];
        char password[50];
        bool status;
    };
    AdminInfo info;

public:

    Admin() {
        std::strcpy(info.username, "admin");
        std::strcpy(info.password, "admin_password");
        info.status = true;
    }

    bool loadAdmin(const std::string& filename) {
        std::ifstream file(filename, std::ios::binary);
        if (file.is_open()) {
            AdminInfo temp;
            while (file.read(reinterpret_cast<char*> (&temp), sizeof (AdminInfo))) {
                if (temp.status) {
                    info = temp;
                    file.close();
                    return true; // add this line
                }
            }
            file.close();
        } else {
            std::cerr << "Unable to open file: " << filename << std::endl;
        }
        return false; // add this line
    }

    void setUser(const std::string& user, const std::string& password) {
        std::strcpy(info.username, user.c_str());
        std::strcpy(info.password, password.c_str());
        info.status = true;

        validateUser();

        std::cout << "Admin : " << info.username << std::endl;
    }

    void createAdminAccount(const std::string& filename, const std::string& username, const std::string& password) {
        std::fstream file(filename, std::ios::in | std::ios::out | std::ios::binary);

        if (file.is_open()) {
            AdminInfo adminInfo;
            std::strcpy(adminInfo.username, username.c_str());
            std::strcpy(adminInfo.password, password.c_str());
            adminInfo.status = true;

            file.seekp(0, std::ios::end);
            file.write(reinterpret_cast<const char*> (&adminInfo), sizeof (AdminInfo));

            file.close();
        } else {
            std::cerr << "Unable to open file: " << filename << std::endl;
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

};

#endif /* ADMIN_H */