#ifndef CMOVIE_H
#define CMOVIE_H

#include <vector>
#include <string>
#include "MOVIESTRUCTURE.h"

class CMovie {
public:
    void MOVIEVALUES(std::vector<Movie> &movies, int nMovies);
};

void saveMoviesToFile(const std::vector<Movie> &movies, const std::string &filename);
void loadMoviesFromFile(std::vector<Movie> &movies, const std::string &filename);
void displayMovie(const Movie &movie);
Movie findMovieByRecordNumber(const std::vector<Movie> &movies, int recordNumber);

#endif // CMOVIE_H
