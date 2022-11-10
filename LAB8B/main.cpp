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
//#define CHECK_SORT
using namespace std;
/*
 * Place prototypes and functions here
 */

/*
 * Function name: trim
 * Description:  Trims space and punctuatuation from ends of a string
 * Returns: Trimmed string
 * Call: s = trim(s); // Where 's' is string to be trimmed
 */
string& trim(string& str, const string& chars = "\t\n\v\f\r.,:;?!-()[]{}<> ") {
    str.erase(0, str.find_first_not_of(chars)); // trim beginning
    str.erase(str.find_last_not_of(chars) + 1); // trim end
    return str; // return trimmed string
}

/**************************************************************************** 
 * Function name: sortList
 * Description: Sorts the supplied word list into alphabetical order
 */
void sortList( string wordlist[],  int counter) {
     int MININDEX;
     string MINVALUE;
    for (int start = 0; start < (counter - 1); start++) {
        MININDEX = start;
        MINVALUE = wordlist[start];
        for (int index = start + 1; index < counter; index++) {
            if (wordlist[index] <  MINVALUE )
              {
                MINVALUE =  wordlist[index];
                MININDEX = index;
            }
        }
                      swap(wordlist[MININDEX], wordlist[start]); 
    }
}
void swap(string wordlist,  string ABC)  {
    string temp; 
    temp = wordlist;
    wordlist= ABC;
    ABC= temp;
}




// ??? Write the function "sortList" by adding code to perform a sort on
// the given list. You may choose either sorting algorithm.

/**************************************************************************** 
 * Main Program
 * Description: 
 *    - Requests a filename from the user and reads words from the file
 *      into an array.
 *    - Sorts the array of words into alphabetical order.
 *    - Queries the user for words then searches for them in the array of 
 *    - sorted words. Outputs the word and it's poistion, or a message
 *      if the word was not found.
 *    - The program exits when the user enters the sentinel value.
 */
int main() {

    string fileName;

    const int MAXWORDS = 5000; // MAX size of word array
    const string sentinel = "xyzzy"; // User entry to end program.

    int counter = 0; // word counter

    // Declare the array that will contain the words.
    string wordList[MAXWORDS] = {};
    // Declare  variable for the user-supplied filename.
    string wordFileName;

    cout << "Enter name of a text file: ";
    cin >> wordFileName;

    ifstream word;
    word.open(wordFileName);

    if (word) { // if file is open

        // Read the words into a partial array
        while (word >> wordList[counter] && counter < MAXWORDS) {
            wordList[counter] = trim(wordList[counter]); // trim punctuation
            counter++;
        } // end of read loop

        word.close();

    }
    else { // file open failed
        cout << "File '" << wordFileName << "' failed to open.";
        exit(2); // Signal that file open failed
    }


    // we call this function in order to sort the input 
    //word-list represents the list of string values that is stored in the program
    //counter represents the number of the positions in terms of integer values.
    sortList(wordList, counter);
    // ??? Below this comment call the sort function to sort array "wordList"
    // into ascending alphabetical order. We are using a partial array,
    // so don't forget to the actual number of elements being used in the
    // array (counter), not MAXWORDS!



    /* DO NOT CHANGE ANY CODE BELOW THIS LINE */

    // If CHECK_SORT is defined, verify order of list.
#ifdef CHECK_SORT
    for (int index = 1; index < counter; index++)
        if (wordList[index] < wordList[index - 1]) {
            cout << "Sort failed at position " << index << ": "
                    << wordList[index] << " < "
                    << wordList[index - 1] << "].\n";
            return 1; // signal that sort failed
        }

    cout << "\nList is sorted!\n";

#else // If CHECK_SORT is not defined, output the whole list  

    for (int index = 0; index < counter; index++)
        cout << wordList[index] << endl;

#endif

    return 0;
}

