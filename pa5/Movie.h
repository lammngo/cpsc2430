#ifndef PA5_MOVIE_H
#define PA5_MOVIE_H
#include <iostream>

using namespace std;

class Movie {
private:
    long id;
    int year;
    int watchCount = 0;
    string title, genre, director, tagline, rating;
public:
    Movie();
    Movie(long movie_id, string movie_name, string movie_type, int movie_year, string movie_director, string movie_rating,
          string movie_tag);
    string getTitle();
    string getGenre();
    string getDirector();
    string getTagLine();
    long getID();
    int getYear();
    void increaseCount();
    int getCount();

};
#endif //PA5_MOVIE_H
