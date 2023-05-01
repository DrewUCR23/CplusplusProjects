#ifndef DEFINITION_H
#define DEFINITION_H

const int SIZE = 31;

struct UserInfo {
    char username[SIZE];
    char password[SIZE];
    bool status;
    bool isAdmin;
};

#endif /* DEFINITION_H */



