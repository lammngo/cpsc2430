#include "GameHeap.h"
#include <iostream>

using namespace std;

GameHeap ::GameHeap() {
    gameList = new Game[MAX_SIZE];
}

GameHeap ::GameHeap(const GameHeap &newGame) {
    gameList = new Game[newGame.MAX_SIZE];
    currentSize = newGame.currentSize;
    MAX_SIZE = newGame.MAX_SIZE;

    for(int i = 0; i < newGame.MAX_SIZE; i++)
        gameList[i] =  newGame.gameList[i];
}

GameHeap & GameHeap ::operator=(const GameHeap &newGame) {
    delete[] gameList;

    gameList = new Game[newGame.MAX_SIZE];
    currentSize = newGame.currentSize;

    for (int i = 0; i < newGame.MAX_SIZE; i++) {
        gameList[i] = newGame.gameList[i];
    }
    return *this;
}
GameHeap ::~GameHeap() {
    delete[] gameList;
}
void GameHeap ::resize() {
    int size = MAX_SIZE;
    //cout << "Size: " << size << endl;
    MAX_SIZE = MAX_SIZE*2;
    //cout << "Max size: " << MAX_SIZE << endl;
    Game* temp = new Game[MAX_SIZE];
    for(int i = 0; i < size; i++){
        //cout << gameList[i].name << endl;
        temp[i] = gameList[i];
        //cout << temp[i].name << endl;
    }
    delete[] gameList;
    //cout << "After deleted: " << endl;
    //print();
    gameList = temp;
}
void GameHeap ::goUp(Game gameList[], int index) {
    int parent = (index-1)/2;
    if (index != 0 && gameList[index].name > gameList[parent].name) {
        Game temp;
        temp = gameList[index];
        gameList[index] = gameList[parent];
        gameList[parent] = temp;
        goUp(gameList, parent);
    }
}
void GameHeap ::insert(string title, int players, int time) {
    if (currentSize + 1 > MAX_SIZE) {
        cout << "The array is full. Resizing array to " << MAX_SIZE*2 << " elements." << endl;
        resize();
    }
    if (title == gameList->name) {
        gameList->maxPlayers = players;
        gameList->playtime = time;
    } else {
        gameList[currentSize].name = title;
        gameList[currentSize].maxPlayers = players;
        gameList[currentSize].playtime = time;
        goUp(gameList, currentSize);
        currentSize++;
    }
}
void GameHeap ::print() {
    for (int i = 0; i < currentSize; i++){
        cout << " arr[" << i << "] = " << gameList[i].name << endl;
    }
}
void GameHeap::findGame(Game *g, string s) {
    bool notFound = true; //create a flag
    for (int i = 0; i < currentSize; i++){
        if (s == g[i].name){
            cout << "Name: " << g[i].name << endl;
            cout << "Maximum # of players: " << g[i].maxPlayers << endl;
            cout << "Playtime: " << g[i].playtime << " minutes" << endl;
            notFound = false;
        }
    }
    if (notFound) {
        cout << s << " is not in the heap." << endl;
    }
}
void GameHeap ::printGame(string name) {
    findGame(gameList, name);
}
void GameHeap ::goDown(Game gameList[], int currentSize, int index) {
    int biggest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < currentSize && gameList[left].name > gameList[biggest].name){
        biggest = left;
    }
    if (right < currentSize && gameList[right].name > gameList[biggest].name){
        biggest = right;
    }
    if (biggest != index){
        Game temp;
        temp = gameList[index];
        gameList[index] = gameList[biggest];
        gameList[biggest] = temp;
        goDown(gameList, currentSize, biggest);
    }
}
string GameHeap ::deleteMax() {
    if (currentSize <= 0){
        return "0";
    }
    if (currentSize == 1){
        currentSize--;
        return gameList[1].name;
    }
    string root = gameList[0].name;
    gameList[0] = gameList[currentSize-1];
    currentSize--;
    goDown(gameList, currentSize, 0);
    cout << "Removing the max value. \"" << root << "\" has been removed." << endl;
    return root;
}

void GameHeap ::makeEmpty() {
    while(currentSize!= 0 && gameList->name != ""){
        deleteMax();
    }
}
