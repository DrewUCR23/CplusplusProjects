#ifndef COMMON_H
#define COMMON_H

const int SIZE = 31;

struct UserInfo {
    char username[SIZE];
    char password[SIZE];
    bool status;
};

#endif /* COMMON_H */
