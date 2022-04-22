#include <iostream>
#include <string>

using namespace std;

typedef string treeElement;

struct BSTNode {
    BSTNode(treeElement my_key, BSTNode* my_left, BSTNode* my_right){
        key = my_key;
        left = my_left;
        right = my_right;
    }
    treeElement key;
    BSTNode* left;
    BSTNode* right;
};

bool insert(BSTNode* &root, treeElement k);
void traverseInOrder(BSTNode* root);
void traversePreOrder(BSTNode* root);
void traversePostOrder(BSTNode* root);
void printLetters(BSTNode* root, string s);
int printSize(BSTNode* root);
void deleteTree(BSTNode* root);

int main() {
    BSTNode* root = nullptr;
    int keys;
    cout << "How many keys do you want to add to the BST? ";
    cin >> keys;
    for (int i = 0; i < keys; i++){
        treeElement k;
        cout << "Enter the key you want to insert: ";
        cin >> k;
        insert(root, k);
    }
    traverseInOrder(root);

    cout << endl;

    string s;
    cout << "Enter a word: ";
    cin >> s;
    cout << "Words that have the same number of letters as " << s << " are: " << endl;
    printLetters(root, s);
    cout << endl;
    cout << "The count of the tree is " << printSize(root) << endl;
    deleteTree(root);
    cout << "The tree is empty now. Goodbye!" << endl;
    root = nullptr;


}

bool insert(BSTNode* &root, treeElement k){
    if (root == nullptr){ // the tree is empty
        root = new BSTNode(k, nullptr, nullptr);
    }
    else {
        BSTNode* temp;
        BSTNode *nextNode; // used to find a free space to insert the k
        temp = root;
        // cout << root->key << " " << temp->key << " "; // what is the root?
        nextNode = temp; // pointing to 1 step ahead compare to the temp

        bool isLeft;

        while (nextNode != nullptr){ // check if nextNode is not a nullptr (is it a free space?)
            temp = nextNode;
            if (k.compare(temp->key) < 0) {
                // cout << "1k: " << k << " temp->key: " << temp->key << endl; // go to the left
                nextNode = temp->left;
                isLeft = true;
            } else if (k.compare(temp->key) > 0){
                // cout << "2k: " << k << " temp->key: " << temp->key << endl; // go to the right
                nextNode = temp->right;
                isLeft = false;
            } else {
                // k = temp->key
                string s;
                cout << "This key is already in the tree. Please enter another key: ";
                cin >> s;
                insert(root, s);
                return false;
            }
        }
        if (isLeft){
            // insert the node to the left of the node that temp is pointing to
            nextNode = new BSTNode(k, nullptr, nullptr);
            temp->left = nextNode;
            // cout << "insert " << k << " to the left of " << temp->key << endl;
        }
        else {
            // insert the node to the right of the node that temp is pointing to
            nextNode = new BSTNode(k, nullptr, nullptr);
            temp->right = nextNode;
            // cout << "insert " << k << " to the right of " << temp->key << endl;
        }
    }
    return true;
}
void traverseInOrder(BSTNode* root){
    if (root == nullptr){
        return;
    } else{
        traverseInOrder(root->left);
        cout << root->key << endl;
        traverseInOrder(root->right);
    }
}
void traversePreOrder(BSTNode* root){
    if (root == nullptr){
        return;
    } else{
        cout << root->key << endl;
        traversePreOrder(root->left);
        traversePreOrder(root->right);
    }
}
void printLetters(BSTNode* currentNode, string s){
    if (currentNode == nullptr){
        return;
    }
    else if (s.size() == currentNode->key.size() && currentNode->key != s){
            cout << currentNode->key;
            cout << endl;
            printLetters(currentNode->left, s);
            printLetters(currentNode->right, s);
        }
}
void traversePostOrder(BSTNode* root){
    if (root == nullptr){
        return;
    } else{
        traversePostOrder(root->left);
        traversePostOrder(root->right);
        cout << root->key << endl;
    }
}
int printSize(BSTNode* currentNode){
    if (currentNode == nullptr){
        return 0;
    }
    else {
        return(printSize(currentNode->left) + 1 + printSize(currentNode->right));
    }
}
void deleteTree(BSTNode* currentNode){
    if (currentNode == nullptr){
        return;
    }
    else{
        deleteTree(currentNode->left);
        deleteTree(currentNode->right);
    }
    delete currentNode;
}
