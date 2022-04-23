#include <iostream>
#include <fstream>
#include <sstream>
#include "GameHeap.h"

using namespace std;

int main() {
    cout << "Hello! Processing the boardgames." << endl;
    ifstream myFile;
    myFile.open("boardgames.csv");

    GameHeap game;
    string name;
    string maxPlayers;
    string playtime;
    string line;

    if (!myFile.is_open()){
        cout << "ERROR!" << endl;
    }

    getline(myFile, line);

    while (getline(myFile, line)){
        stringstream ss(line);
        getline(ss, name, ',');
        getline(ss, maxPlayers, ',');
        getline(ss, playtime, '\n');
        game.insert(name, stoi(maxPlayers), stoi(playtime));
        //cout << "Names: " << name << endl;
        //game.print();
    }
    myFile.close();
    GameHeap heap2(game);          //copy constructor
    GameHeap heap3;                //copy assignment
    heap3 = game;
    cout << endl;
    game.print();
    string s;
    cout << endl << "Which game do you want to print? ";
    getline(cin, s);
    game.printGame(s);
    for (int i = 0; i < 2; i++){
        cout << endl;
        game.deleteMax();
        cout << "Printing the updated heap:" << endl;
        cout << endl;
        game.print();
    }
    cout << endl << "Created heap 2 with copy constructor copying heap 1:" << endl;
    heap2.print();
    cout << endl << "Deleting max value of heap 2:" << endl;
    heap2.deleteMax();
    cout << "Deleting max value of heap 2:" << endl;
    heap2.deleteMax();
    cout << endl << "Emptying heap 2..." << endl;
    heap2.makeEmpty();

    cout << endl << "Created heap 3 with copy assignment copying heap 2:" << endl;
    heap3.print();
    cout << endl << "Inserting Candy Crush into heap 3..." << endl;
    heap3.insert("Candy Crush", 7 , 69);
    cout << "Inserting Maze Runner into heap 3..." << endl;
    heap3.insert("Maze Runner", 20, 120);
    cout << endl << "Emptying heap 3..." << endl;
    heap3.makeEmpty();

    cout << endl << "This is the end of the execution example. Goodbye!";
}
