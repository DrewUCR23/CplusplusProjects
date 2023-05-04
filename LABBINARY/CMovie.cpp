#include "CMovie.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
using namespace std;

// Function to create movie records using the MOVIEVALUES method
void CMovie::MOVIEVALUES(vector<Movie> &movies, int nMovies) {
    srand(static_cast<unsigned> (time(nullptr)));
    for (int i = 0; i < nMovies; i++) {
        Movie movie;
        strcpy(movie.name, ("Movies" + to_string(i)).c_str());
        strcpy(movie.director, ("Drew" + to_string(i)).c_str());
        movie.year = (rand() % 64) + 1985;
        movie.runtime = (rand() % 101) + 80;
        movies.push_back(movie);
    }
}

// Function to save movie records to a binary file
void saveMoviesToFile(const vector<Movie> &movies, const string &filename) {
    ofstream outputFile(filename, ios::binary);
    for (const Movie &movie : movies) {
        outputFile.write(reinterpret_cast<const char*> (&movie), sizeof (Movie));
    }
    outputFile.close();
}

// Function to load movie records from a binary file
void loadMoviesFromFile(vector<Movie> &movies, const string &filename) {
    ifstream inputFile(filename, ios::binary);
    if (!inputFile) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }
    movies.clear();
    Movie movie;
    while (inputFile.read(reinterpret_cast<char*> (&movie), sizeof (Movie))) {
        movies.push_back(movie);
    }
    inputFile.close();
}

// Function to display a movie record
void displayMovie(const Movie &movie) {
    cout << "Movie Name: " << movie.name << endl;
    cout << "Movie Director: " << movie.director << endl;
    cout << "Year Released: " << movie.year << endl;
    cout << "Run Time: " << movie.runtime << " minutes" << endl;
}

// Function to find a movie record by record number
Movie findMovieByRecordNumber(const vector<Movie> &movies, int recordNumber) {
    if (recordNumber >= 1 && recordNumber <= static_cast<int> (movies.size())) {
        return movies[recordNumber - 1]; // Convert 1-based index to 0-based index
    }
    return Movie(); // Return an empty movie if not found
}


