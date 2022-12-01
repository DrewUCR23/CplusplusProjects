/*
 * CSC/CIS-5-48306/48260 Program Logic Using C++ Fall 2022
 *
 * STUDENT:   Drew Gonzales
 * ASSIGNMENT: Lab Exercise 10
 * DUE DATE:   12/03/2022
 *
 */
/* Place Library References Here */
#include <cstdlib>
#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;
/* Global Constants */
const int MAX_SENSITIVE_WORDS = 100;
const string REPLACEMENT_TEXT = "[redacted]";
/*
 * Function Pototypes and Definitions
 */

/*
 * Function Name: openInputFile
 * Descritpion:   Opens input file using stream object
 *                and prompts supplied by the caller. A
 *                rety count is included.
 *
 */
bool openInputFile(ifstream &stream,
        string prompt1 = "Enter filename: ",
        string prompt2 = "File failed to open.\n",
        string prompt3 = "Re-enter filename: ",
        int retryCount = 3) {
    string filename = "";
    int retries = 0;
    // Open input file
    cout << prompt1;
    getline(cin, filename);
    if (cin.eof() || filename == "") // EOF or empty?
        return false;
    stream.open(filename);
    while (!stream.is_open()) {
        // Manage retries (retries diabled if retryCount = 0)
        if (retryCount > 0 && retries >= retryCount) {
            cout << "Retry count exhausted.\n";
            return false; // Retries exceeded
        }
        retries++;
        cout << prompt2 << endl; // error message
        cout << prompt3;
        getline(cin, filename);
        if (cin.eof() || filename == "") // EOF or empty?
            return false;
        stream.open(filename);
    }
    cout << "\n\"" << filename << "\" is open.\n";
    return true;
}

/*
 * Main Program
 *
 * Description: Read a dirty word list, then read a source text file line-by-line
 * line-by-line and replace every occurence of a word that from the dirty word list
 * that is in the the source text with the replacement text.
 *
 */
int main() {

    /**********************************************************************************
     ************
     *
     * Open and read sensitive word list
     *
     */
    string sensitiveWords[MAX_SENSITIVE_WORDS]; // Array to hold "dirty words"
    int sensitiveWordlistSize = 0; // Number of "dirty words" read.
    // Declare dirty word input stream object
    ifstream sensitiveWordInput;
    // If dirty word file opens
    if (openInputFile(sensitiveWordInput,
            "What is the name of the file containing the sensitive word list? ",
            "File failed to open.\n",
            "Re-enter sensitive word list filename:")) {
        // Read sensitive word list
        while (sensitiveWordlistSize < MAX_SENSITIVE_WORDS &&
                getline(sensitiveWordInput, sensitiveWords[sensitiveWordlistSize]))
            sensitiveWordlistSize++;
        cout << sensitiveWordlistSize << " sensitive words read." << endl << endl;
        sensitiveWordInput.close();

        /**********************************************************************************
         ************
         *
         * Open sensitive text file to be sanitized
         *
         */
        string STF;
        // declare input stream
        ifstream textInput;
        ofstream REDACTEDT; 
        REDACTEDT.open("OUTPUTFILE.txt");
        if (openInputFile(textInput,
                "What is the name of the text file containing the sensitive text?",
                "File failed to open.\n",
                "Re-enter the name of the file containing the sensitive text: ")) {
            cout << "\nSensitive text file is open.\n";
            while (textInput) {
                getline(textInput, STF);
//search  for the string values in the while loop   
          // if(STF.find(sensitiveWords)) 
                for (int i = 0; i < sensitiveWordlistSize; i++) {
                   if(STF.find(sensitiveWords[i])!=string::npos) { 
                       size_t pos = STF.find(sensitiveWords[i]);
                       // finds the position of the string 
            STF.replace(pos, sensitiveWords[i].length(), REPLACEMENT_TEXT);
                   }
                }
                 REDACTEDT << STF << endl;                 
            }

            textInput.close();
        } else
            cout << "\nSensitive text file failed to open.";
    } else
        cout << "\nSensitive word file failed to open.";
    cout << "\nProgram complete.\n";
    return 0;
} // end ofmain program
