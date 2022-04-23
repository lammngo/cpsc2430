#include <iostream>
#include "Movie.h"

using namespace std;

Movie ::Movie() {
    this->id = 0;
    this->title = "";
    this->genre = "";
    this->year = 0;
    this->director = "";
    this->rating = "";
    this->tagline = "";
}
Movie ::Movie(long movie_id, string movie_name, string movie_type, int movie_year, string movie_director, string movie_rating,
              string movie_tag){
    this->id = movie_id;
    this->title = movie_name;
    this->genre = movie_type;
    this->year = movie_year;
    this->director = movie_director;
    this->rating = movie_rating;
    this->tagline = movie_tag;
}
//void Movie::printMovie() {
//    for (int i = 0; i < rating.size(); i++){
//        if (rating[i] == '-')
//            rating[i] = ',';
//    }
//    for (int i = 0; i < tagline.size(); i++){
//        if (tagline[i] == ';') {
//            tagline[i] = ',';
//        }
//    }
//    cout << "Title: " << title
//            << "\nGenre: " << genre
//            << "\nDirector: " << director
//            << "\nTagline: " << tagline
//            << "\nRating: " << rating
//            << "\nID: " << id
//            << "\nRelease year: " << year << endl;
//}
string Movie ::getTitle() {
    return title;
}
string Movie::getGenre() {
    return genre;
}
string Movie::getDirector() {
    return director;
}
string Movie ::getTagLine() {
    return tagline;
}
long Movie ::getID() {
    return id;
}
int Movie ::getYear() {
    return year;
}
void Movie ::increaseCount() {
    watchCount++;
}
int Movie ::getCount() {
    return watchCount;
}

