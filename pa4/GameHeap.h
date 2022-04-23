#ifndef PA4_GAMEHEAP_H
#define PA4_GAMEHEAP_H
#include <iostream>

using namespace std;


class GameHeap {
private:
    struct Game {
        string name;
        int maxPlayers;
        int playtime;
    };
    Game* gameList;
    int MAX_SIZE = 4;
    int currentSize = 0;
    void goUp(Game gameList[], int index);
    void findGame(Game* g, string s);
    void goDown(Game gameList[], int currentSize, int index);

public:
    GameHeap();
    GameHeap(const GameHeap& newGame);
    GameHeap& operator=(const GameHeap& newGame);
    ~GameHeap();
    void resize();
    void insert(string title, int players, int time);
    void print();
    void printGame(string name);
    string deleteMax();
    void makeEmpty();

};

#endif //PA4_GAMEHEAP_H
