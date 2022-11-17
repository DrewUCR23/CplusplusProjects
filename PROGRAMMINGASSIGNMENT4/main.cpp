
/*
 * CSC/CIS-5-48306/48260 Program Logic Using C++ Fall 2022
 *
 * STUDENT:    Drew Gonzales
 * ASSIGNMENT: Lab Exercise 8b
 * DUE DATE:   11/12/2022
 *
 */
/* Place Library References Here */
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int POLICYRULES[5];
//const string chars = PW_SPECIAL_CHARS;
/*
 * Determine if any of the characters in the password
 * are in some character range 'first' to 'last' (inclusive)
 *
 * To call it:  if (characterPresent(password, 'a', 'b'))
 *
 * will return true if the 'password' string contains any
 * characters between the two characters 'a' and 'z'.
 * This can also be used for 'A' and 'Z'  and '0' and '9'.
 */
bool CHARACTERPRESENT(string password, char first, char last) {
    // Loop through all characters of the password and look for
    // at least one that is within the requested range, then return
    // 'true'. Return 'false' if not found.
    for (int i = 0; i < password.length(); i++) {
        if (password[i] >= first && password[i] <= last) {
            return true;
        }
    }
    return false;
}

/*
 * Determine if any of the characters in the password
 * is a special character.
 *
 *   to call: if (characterPresent(password))
 *
 *   will return true if any of the characters in 'password' are
 *   also in 'chars'. Used to check for secial characters in the passwrord.
 */
bool CHARACTERPRESENT(string password, const string chars ="~`!@#$%^&*()_+-=[]{}|\\:;\"'?/>.<,") {

    // Loop through all characters of the password and look for
    // at least one tht is a special character, then return
    // 'true'. Return 'false' if not found.
    for (int i = 0; i < password.length(); i++) {
        if (chars.find(password[i]) != string::npos) {
            return true;
        }
    }
    return false;
}

/**************************************************************************** 
 * Function name: sortList
 * Description: Sorts the supplied word list into alphabetical order
 */
void PASSWORDPOLICY(ifstream & FILE, int COUNTER, string FILENAME) {
    if (FILE) { // if file is open
        //for extracing >>
        // Read the words into a partial array

        cout << "PASSWORD POLICY" << endl;
        while (FILE >> POLICYRULES[COUNTER]) {
            COUNTER++;
        }
        // POLICY PRINT OUT TO USER
        cout << "Policy File" << FILENAME << "loaded:" << endl;
        cout << "Minimum password length:" << POLICYRULES[0] << endl;
        if (POLICYRULES[1] == 1) {
            cout << "Low Case Required:" << "YES" << endl;
        } else {
            cout << "Low Case Required:" << "NO" << endl;
        }
        if (POLICYRULES[2] == 1) {
            cout << "Upper Case Case Required:" << "Yes" << endl;
        } else
            cout << "Upper Case Required:" << "NO" << endl;
        if (POLICYRULES[3] == 1) {
            cout << "Digits Case Required:" << "YES" << endl;
        } else
            cout << "Digits Required:" << "NO" << endl;
        {
            if (POLICYRULES[4] == 1) {
                cout << "Special Character Required:" << "YES" << endl;
            } else
                cout << "Special Character Required:" << "NO" << endl;
        }
    }
}
bool CHECKPASSWORDPOLICY(int POLICYRULES[], int COUNTER, string PASSWORD) {
    //CHECK FOR THE LENGTH OF THE PASSWORD
    bool PWTRUE = false;
    if (PASSWORD.length() >= POLICYRULES[0]) {
        PWTRUE = true;
    }
    //CHECK IF ITS LOWER CASE  
    if (POLICYRULES[1] == 1) {
        PWTRUE = CHARACTERPRESENT(PASSWORD, 'A', 'Z');
        if (PWTRUE == false) {
            cout << "LowerCase Required" << endl;
           // return (PWTRUE);
        }
    }
    //CHECK IF IT'S UPPER CASE
    if (POLICYRULES[2] == 1) {
        PWTRUE = CHARACTERPRESENT(PASSWORD, 'a', 'z');
        if (PWTRUE == false) {
            cout << " It needs uppercase values" << endl;
            //return (PWTRUE);
        }
    }
    // CHECK FOR DIGITS REQUIRED
    if (POLICYRULES[3] == 1) {
        PWTRUE = CHARACTERPRESENT(PASSWORD, '0', '9');
        if (PWTRUE == false) {
            cout << "Digits are required" << endl;
            //return (PWTRUE);
        }
    }
    // CHECK FOR SPECIAL CHARACTERS SPECIAL CHARACTER
    const string chars = "~`!@#$%^&*()_+-=[]{}|\\:;\"'?/>.<,";
    if (POLICYRULES[4] == 1) {
       // for (int i = 0; i < PASSWORD.length(); i++) {
        //if (chars.find(PASSWORD[i]) != string::npos) {
           PWTRUE = CHARACTERPRESENT(PASSWORD, chars);
        }
            if (PWTRUE == false) {
                cout << "Special characters are required" << endl;
             //   return (PWTRUE);
            }
            cout << "PASSWORD PASSES" << endl;
           // return (PWTRUE);
        }
    int main() {
        string PASSWORD, FILENAME;
        bool PWTRUE = false;
        int COUNTER = 0; // word counte
        // Declare  variable for the user-supplied filename.
        cout << "Enter the name of the password policy file:";
        cin >> FILENAME;
        ifstream FILE;
        FILE.open(FILENAME);
        //CALL PASSWORDPOLICY TO READ OUT THE POLICY TO THE USER:
        PASSWORDPOLICY(FILE, COUNTER, FILENAME);
        // ask the user to enter a password
        cin.ignore();
        do {      
          cout << "Enter a password(blank to exit):" << endl;
            getline(cin, PASSWORD); 
            if(PASSWORD == "") {
                exit(0);
            }
      PWTRUE = CHECKPASSWORDPOLICY(POLICYRULES, COUNTER, PASSWORD);
       }while(PASSWORD != "");
        // CLOSES THE FILE 
        FILE.close();
        return 0;
    }

