#include "GameBST.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ifstream myFile;
    myFile.open("boardgames.csv");

    GameBST tree;
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

        tree.insert(name, stoi(maxPlayers), stoi(playtime));
    }
    myFile.close();

    cout << "Hello! Processing the boardgames.csv file. \n" <<
            "Tree height is " << tree.getHeight() << endl;

    cout << "Printing tree:" << endl;
    tree.print();
    cout << endl;
    string s;
    cout << "Which game do you want to print? ";
    getline(cin, s);
    tree.printGame(s);
    cout << endl;
    string n;
    cout << "Which game do you want to remove? ";
    getline(cin, n);
    tree.remove(n);
    tree.print();
    cout << endl;
    int i;
    cout << "How much time do you have (in mins)? ";
    cin >> i;
    cout << "Games you can play in " << i << " minutes are:" << endl;
    tree.printPlayable(i);
    cout << endl;
    cout << "Printing a copied tree..." << endl;
    cout << endl;
    GameBST tree2(tree);
    tree2.print();
    cout << endl;
    GameBST tree3(tree);
    cout << "Printing a shallow copied tree..." << endl;
    cout << endl;
    tree3.insert("Candy Shop", 10, 69);
    tree3.print();
}
