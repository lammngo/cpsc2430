#ifndef PA5_HASHTABLE_H
#define PA5_HASHTABLE_H
#include "Movie.h"

const int MAX_SIZE = 7;
class HashTable {
private:
    struct MovieNodes{
        long key;
        Movie value;
        MovieNodes* next; //movie pointer next
        MovieNodes(long k, Movie m){ //MovieNode parameterized constructor
            key = k; //the id of the movie
            value = m; //object movie
            next = nullptr;
        }
    };
    MovieNodes** playlist; //hash table for the movies
    int numItems; //total movies

public:
    HashTable();
    ~HashTable();
    void addToPlaylist(long key, Movie value);
    bool watchMovie(long key);
    void removeMovie(long key);
    void displayMovie(long key);
    void displayAll();
    void displayGenre(string genre);
};

#endif //PA5_HASHTABLE_H
