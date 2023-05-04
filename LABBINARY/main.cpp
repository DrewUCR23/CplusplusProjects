#include <iostream>
#include <string>
#include <vector>
#include "CMovie.h"
#include "MOVIESTRUCTURE.h"
#include <cstring>

using namespace std;

int main() {
    vector<Movie> movies;
    CMovie cmovie;

    // Create 100 movie records and specifies the size
    cmovie.MOVIEVALUES(movies, 100);

    // Save movie records to a binary file
    string filename = "MOVIE.bin";
    saveMoviesToFile(movies, filename);

    // Prompt the user for the file name
    cout << "Enter the file name you want to open: ";
    cin >> filename;

    // Load movie records from the binary file
    loadMoviesFromFile(movies, filename);

    // Prompt the user for a record number and display the movie record if found
    int recordNumber;
    cout << "Enter the movie record number to search (1-100): ";
    cin >> recordNumber;
    Movie movie = findMovieByRecordNumber(movies, recordNumber);
    if (strlen(movie.name) > 0) {
        displayMovie(movie);
    } else {
        cout << "Movie not found." << endl;
    }

    return 0;
}


