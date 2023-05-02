#ifndef COMMON_H
#define COMMON_H

const int SIZE = 31;

struct UserInfo {
    char username[SIZE];
    char password[SIZE];
    bool status;
    bool isAdmin; 
};

#endif /* COMMON_H */
