#include <iostream>
#include "HashTable.h"

using namespace std;

HashTable ::HashTable() {
    numItems = 0;
    playlist = new MovieNodes*[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
        playlist[i] = nullptr;
}
HashTable ::~HashTable() {
    for(int i = 0; i < MAX_SIZE; i++){
        if(playlist[i] != nullptr){
            MovieNodes* ptr;
            MovieNodes* curr = playlist[i];
            while(curr){
                ptr = curr;
                curr = curr->next;
                delete ptr;
            }
        }
    }
    delete[] playlist;
}
void HashTable::addToPlaylist(long key, Movie value) {
    int index = key % MAX_SIZE; //find the hash key

    MovieNodes* newMovie = new MovieNodes(key, value); //create a new movie
    numItems++; //increase num of movies

    if(playlist[index] == nullptr){ //if there's no nodes in that hash key
        playlist[index] = newMovie; //insert the new movie in that index
    } else {
        MovieNodes* ptr = playlist[index]; //create a pointer pointing to the hash key
        while(ptr->next && ptr->key != key){ //while we had a movie in this hash key and its different from the new movie
            ptr = ptr->next; //find new location for the new movie, which is the ptr->next
        } if(ptr->key == key) { //if the key is already exist
            cout << "The movie is already in your playlist." << endl;
        } else {
            ptr->next = newMovie; //insert the new movie in the next index of the existed movie
        }
    }
}

void HashTable::displayAll() {
    MovieNodes* ptr;
    for(int i = 0; i < MAX_SIZE; i++){
        if(playlist[i]){
            ptr = playlist[i];
            while(ptr){
                cout << endl << "IMDb id: " << ptr->key
                << "\nTitle: " << ptr->value.getTitle();
                cout << endl;
                ptr = ptr->next;
            }
        }
    }
}
void HashTable ::displayGenre(string genre) {
    MovieNodes* ptr;
    for(int i = 0; i < MAX_SIZE; i++){
        if(playlist[i]){
            ptr = playlist[i]; //go to the linked list at i index
            while(ptr){
                if(genre == ptr->value.getGenre()){
                    cout << endl << "IMDb id: " << ptr->key
                         << "\nTitle: " << ptr->value.getTitle()
                         << endl;

                }
                ptr = ptr->next;
            }
        }
    }
}
bool HashTable ::watchMovie(long key) {
    MovieNodes* ptr;
    for(int i = 0; i < MAX_SIZE; i++){
        if(playlist[i]){
            ptr = playlist[i]; //go to the linked list at i index
            while(ptr){
                if(key == ptr->value.getID()){
                    cout << "Watch " << ptr->value.getTitle() << ". ";
                    ptr->value.increaseCount();
                    cout << "Increased watchCount to " << ptr->value.getCount() << endl;
                    return true; //after finding a movie in the playlist
                }
                ptr = ptr->next;
            }
        }
    }
    return false; //after traversing to all the elements in the playlist, the key is not in there, so we return false
}
void HashTable ::displayMovie(long key) {
    MovieNodes* ptr;
    for(int i = 0; i < MAX_SIZE; i++){
        if(playlist[i]){
            ptr = playlist[i]; //go to the linked list at i index
            while(ptr){
                if(key == ptr->value.getID()){
                    cout << "IMDb id: " << ptr->value.getID() << endl
                         << "Title: " << ptr->value.getTitle() << endl
                         << "Director: " << ptr->value.getDirector() << endl
                         << "Genre: " << ptr->value.getGenre() << endl
                         << "Tagline: " << ptr->value.getTagLine() << endl
                         << "Year: " << ptr->value.getYear() << endl
                         << "You've watched it " << ptr->value.getCount() << " time(s)." << endl;
                    break;
                }
                ptr = ptr->next;
            }
        }
    }
}
void HashTable ::removeMovie(long key) {
    MovieNodes *ptr;
    MovieNodes *nextPtr;
    bool notFound = true;
    for (int i = 0; i < MAX_SIZE && notFound; i++) {
        if (playlist[i]) { //current node/first node
            ptr = playlist[i]; //go to the linked list at i index
            while (ptr && notFound) {
                nextPtr = ptr->next;
                //Test if the current node is the node we need to remove
                if (key == ptr->value.getID()) {
                    cout << "Removing " << ptr->value.getTitle() << " from the playlist." << endl;
                    //If there's only 1 node, or it's the last node
                    if (nextPtr == nullptr) {
                        ptr->next = nullptr;
                        delete ptr;
                        notFound = false;
                        numItems--;
                    } else { //if the node is in the middle of the linked list
                        ptr->next = nextPtr->next;
                        delete nextPtr;
                        //todo: also decrease the numItems count
                        numItems--;
                        notFound = false;
                    }
//                    ptr->next = nextPtr->next;
//                    delete nextPtr;
//                    notFound = false;
//                    //todo: also decrease the numItems count
//                    numItems--;
                }
                //Test next node also
                else if (nextPtr && key == nextPtr->value.getID()) {
                    cout << "Removing " << nextPtr->value.getTitle() << " from the playlist." << endl;
                    ptr->next = nextPtr->next;
                    delete nextPtr;
                    numItems--;
                    notFound = false;
                }
                //Otherwise, move on
                else {
                    ptr = ptr->next;
                }
            }
        }
    }
}



