#include "GameBST.h"

GameBST::GameBST() {
    root = nullptr;

}
GameBST::TreeNode* GameBST:: otherTree(TreeNode* root){
    if (root == nullptr){
        return nullptr;
    } else {
        return new TreeNode{root->key, root->maxPlayers, root->playtime,
                            otherTree(root->left), otherTree(root->right)};
    }
}

GameBST ::GameBST(const GameBST &newTree) {
    root = otherTree(newTree.root);
}
void GameBST ::makeEmpty(TreeNode *p) {
    if (p != nullptr){
        makeEmpty(p->left);
        makeEmpty(p->right);
        delete p;
    }
}

GameBST & GameBST ::operator=(const GameBST &newTree) {
    makeEmpty(root);
    root = otherTree(newTree.root);
    return *this;
}
GameBST :: ~GameBST() {
    makeEmpty(root);
}
GameBST :: TreeNode* GameBST ::findMin(TreeNode *node) {
    if (node == nullptr)
        return nullptr;
    if (node->left == nullptr)
        return node;
    return findMin(node->left);
}
bool GameBST ::remove(string name) {
    return removeHelper(root, name);
}

bool GameBST ::removeHelper(TreeNode* &r, string n) {
    if (r == nullptr)
        return false;
    if (n < r->key) {
        removeHelper(r->left, n);
    } else if (n > r->key){
        removeHelper(r->right, n);
    } else if (r->left != nullptr && r->right != nullptr){
        r->key = findMin(r->right)->key;
        removeHelper(r->right, r->key);
    } else {
        TreeNode* oldNode = r;
        r = (r->left != nullptr) ? r->left : r->right;
        delete oldNode;
    }
}

int GameBST ::treeHeight(TreeNode *p) {
    if (!p){
        return -1;
    }
    else{
        int left_height = treeHeight(p->left);
        int right_height = treeHeight(p->right);
        if (left_height > right_height){
            return left_height + 1;
        } else {
            return right_height + 1;
        }
    }
}

int GameBST ::getHeight() {
    return treeHeight(root);
}
GameBST ::TreeNode* GameBST ::insertNode(TreeNode * &r, string name, int player, int time) {
    if (r == nullptr){ 
        r = new TreeNode;
        r->key = name;
        r->maxPlayers = player;
        r->playtime = time;
        r->left = nullptr;
        r->right = nullptr;
    }
    else if(r->key > name)
        insertNode(r->left, name, player, time);
    else
        insertNode(r->right, name, player, time);

    return r;
}
void GameBST ::insert(string name, int player, int time) {
    insertNode(root, name, player, time);
}

void GameBST ::printInOrder(TreeNode *root) {
    if (root == nullptr){
        return;
    } else{
        printInOrder(root->left);
        cout << root->key << endl;
        printInOrder(root->right);
    }
}
void GameBST::print() {
    printInOrder(root);
}
void GameBST ::findGame(TreeNode *p, string s) {
    if (s == p->key){
        cout << "Game: " << p->key << endl
             << "Maximum # of players: " << p->maxPlayers << endl
             << "Minimum playtime: " << p->playtime << " mins" << endl;
    }
    else if (p->key < s){
        findGame(p->right, s);
    } else {
        findGame(p->left, s);
    }
}
void GameBST ::printGame(string name) {
    findGame(root, name);
}

void GameBST ::printPlayable(int timeLeft) {
    traversePostOrder(root, timeLeft);
}

void GameBST ::traversePostOrder(TreeNode* p, int time) {
    if (p == nullptr){
        return;
    } else{
        traversePostOrder(p->left, time);
        traversePostOrder(p->right, time);
        if (p->playtime <= time){
            cout << p->key << endl;
        }
    }
}


