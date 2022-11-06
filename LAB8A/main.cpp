/*
 * CSC/CIS-5-48306/48260 Program Logic Using C++ Fall 2022
 *
 * STUDENT:    Drew Gonzales
 * ASSIGNMENT: Lab Exercise 8a
 * DUE DATE:   11/05/2022
 *
 */

/* Place Library References Here */

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

// Uncomment next line to display word list.
//#define OUTPUT_WORDS
#define LINE_LENGTH 50 // Words per line to display

/*
 * Place prototypes and functions here
 */

/*
 * Function name: trim
 * Description:  Trims space and punctuatuation from ends of a string
 * Returns: Trimmed string
 * Call: s = trim(s); // Where 's' is string to be trimmed
 */
string& trim(string& str, const string& chars = "\t\n\v\f\r.,:;?!-()[]{}<> ")
{
  str.erase(0, str.find_first_not_of(chars)); // trim beginning
  str.erase(str.find_last_not_of(chars) + 1); // trim end
  return str;  // return trimmed string
}


/************************************************************************
 * Function name: linearSearch
 * Description: Given an array of strings, an array size, a keyword and a start
 *              position, returns the position of the next occurrence of the
 *              keyword.
 *              Returns -1 if not found;
 */
int linearSearch(string wordList[], int size, string searchValue, int start=0);
// ??? Write the linear search function here or following the main program.



/************************************************************************
 * Function name: binary Search
 * Description: Given an array of strings, the array size and a keyword
 *              to search, return the position of the keyword.
 *              Returns -1 if not found;
 */
int binarySearchString(string wordList[], const int SIZE, string searchValue) {
    {
        int first = 0, // First array element
                last = SIZE - 1, // Last array element
                middle, // Mid point of search
                position = -1; // Position of search value
        bool found = false; // Flag
        while (!found && first <= last) {
            middle = (first + last) / 2; // Calculate mid point
            if (wordList[middle] == searchValue) // If value is found at mid
            {
                found = true;
                position = middle;
            } else if (wordList[middle] > searchValue) // If value is in lower half
                last = middle - 1;
            else
                first = middle + 1; // If value is in upper half
        }
        return position;
    }
}
/************************************************************************
 * Function name: Recursive Binary Search
 * Description: Given an array of strings, the start and end positions
 *              and a search value, returns the position of the
 *              search value in the array.
 *              Returns -1 if not found;
 *
 *     Notice that this function name is overloaded
 */
int binarySearch (string wordList[], int start, int end, string searchValue);
// ??? Write the recursive binary search here or following the main program.


/************************************************************************
 *
 * Main Program
 * Description: Reads words from a file, stores them into an array, then searches the array
 *              for words entered by the user.
 *
 */
int main() {
  string fileName;
  /* Contants */
  const int    MAXWORDS = 5000;    // Maximum number of words
  const string SENTINEL = "xyzzy"; // User entry to end input

  /* Variables */
  string wordList[MAXWORDS] = {};   // Array to hold the words
  string wordFileName = "";         // Filename entered by the user.
  string searchv; 
  int results; //defined for search valus for word using binary function
  // Get input file name from user
  cout << "Enter the name of a text file to search: ";
  cin  >> wordFileName;
  // Open requested file
  ifstream word;
  word.open(wordFileName);

  // If file is open, process the word file
  if (word) {

    // Acknowledge filename to user
    cout << "Searching '" << wordFileName << "'.\n\n";

    // Read the words into a partial array
    int counter = 0;
    while (word >> wordList[counter] && counter < MAXWORDS) {
      wordList[counter] = trim(wordList[counter]); // trim punctuation
      counter ++;
    }
    word.close();
    // NOTICE: At this point there are "counter" words inthe word list array.
#ifdef OUTPUT_WORDS // Only output words if "OUTPUT_WORDS" is defined
    int lineLength = 0;
    for (int i = 0; i < counter; i++) {
      cout << wordList[i];
      lineLength += wordList[i].length();
      if (lineLength < LINE_LENGTH)
	cout << " ";
      else { // Output new line
	lineLength = 0;
	cout << endl;
      }
    }
#endif
    // ??? Write a loop and that will ask the operator for a word,
    // search for that word in the list using the chosen search,
    // then list the word and it's position(s). Exit when the user
    // enters "xyzzy". (Gamers will be familiar with this word.
    // Posers will have to look it up.)
    // ??? Put code here
   
   // for (int i = 0; i <MAXWORDS; i++){
     //       cout<<"words stored:"<<wordList[i]<<endl;
    //}
   cout<<"Enter a word:"<<endl;
    cin>>searchv;
    //search for name
    results = binarySearchString(wordList, counter,  searchv);
    cout<<"The word is:"<<wordList[results]<<endl;
  }
  else {  // File open failed
    cout << "File '" << wordFileName << "' failed to open.";
    exit (1);
  }
  return 0;
}

