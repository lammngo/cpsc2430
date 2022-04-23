#ifndef PA3_GAMEBST_H
#define PA3_GAMEBST_H
#include <iostream>

using namespace std;


class GameBST {
private:
    struct TreeNode{
        string key;     //name of the game
        int maxPlayers; //maximum number of players
        int playtime;   //minimum playtime
        TreeNode* left;
        TreeNode* right;
    };
    TreeNode* root;
    TreeNode* otherTree(TreeNode* root);
    TreeNode* insertNode(TreeNode* &root, string name, int player, int time);
    void printInOrder(TreeNode* root);
    void findGame(TreeNode* p, string s);
    TreeNode* findMin(TreeNode* node);
    bool removeHelper(TreeNode* &r, string name);
    int treeHeight(TreeNode* p);
    void traversePostOrder(TreeNode* p, int time);
    void makeEmpty(TreeNode* p);

public:
    GameBST();
    GameBST(const GameBST& newTree);
    GameBST& operator=(const GameBST& newTree);
    ~GameBST();
    void insert(string name, int player, int time);
    bool remove(string name);
    void printGame(string name);
    void print();
    int getHeight();
    void printPlayable(int timeLeft);
};


#endif //PA3_GAMEBST_H
