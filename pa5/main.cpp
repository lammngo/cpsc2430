#include <iostream>
#include "Movie.h"
#include "HashTable.h"
#include <fstream>
#include <sstream>

using namespace std;

int main() {

    ifstream myFile;
    myFile.open("movies-sample.csv");

    HashTable movie;
    string line;
    string id,title,genre,release_year,director,content_rating,tagline;

    if (!myFile.is_open()){
        cout << "ERROR!" << endl;
    }

    getline(myFile, line);

    while(getline(myFile, line)){
        stringstream ss(line);
        getline(ss, id, ',');
        getline(ss, title, ',');
        getline(ss, genre, ',');
        getline(ss, release_year, ',');
        getline(ss, director, ',');
        getline(ss, content_rating, ',');
        getline(ss, tagline);

        string::size_type  sz;

        Movie addMovie = Movie(stol(id, &sz), title, genre,
                               stoi(release_year), director, content_rating, tagline);
        movie.addToPlaylist(stol(id), addMovie);
    }
    int choice;
    long userInput;
    bool inMenu = true;

    string s;
    cout << "Welcome to my movie world! What would you like to do?" << endl;
    while(inMenu){
        cout << "1. Browse all movies, 2. Browse by genre, 3. Watch a movie, " << endl
        << "4. Get movie info, 5. Remove movie: ";
        cin >> choice;
        switch (choice) {
            case 1:
                movie.displayAll();
                cout << endl << "*************************" << endl;
                break;
            case 2:
                cout << endl << "Which genre are you looking for? ";
                cin >> s;
                movie.displayGenre(s);
                cout << endl << "*************************" << endl;
                break;
            case 3:
                cout << endl << "Enter the ID of the movie you want to watch: ";
                cin >> userInput;
                movie.watchMovie(userInput);
                cout << endl << "*************************" << endl;
                break;
            case 4:
                cout << endl << "Enter the ID of the movie: ";
                cin >> userInput;
                movie.displayMovie(userInput);
                cout << endl << "*************************" << endl;
                break;
            case 5:
                cout << endl << "Enter the ID of the movie you want to remove: ";
                cin >> userInput;
                movie.removeMovie(userInput);
                cout << endl << "*************************" << endl;
                break;
            default:
                cout << endl << "*************************" << endl;
                cout << "Hope you enjoyed the movies. Goodbye!";
                inMenu = false;
        }
    }
    return 0;
}
