
#ifndef MOVIESTRUCTURE_H
#define MOVIESTRUCTURE_H

#ifdef __cplusplus
extern "C" {
#endif

struct Movie {
    char name[50];
    char director[50];
    int year;
    int runtime;
};



#ifdef __cplusplus
}
#endif

#endif /* MOVIESTRUCTURE_H */

