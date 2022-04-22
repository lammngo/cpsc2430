#include <iostream>
using namespace std;

typedef int ElementType;
struct Node{
    ElementType data;
    Node* next;
};

void print(Node* nPtr, int x);
void list(Node* &front, ElementType data);
void deallocate(Node* &front);

int main() {
    Node* front = nullptr;
    ElementType input;
    cout << "Welcome. How many elements do you want to add to the list? ";
    cin >> input;
    int size = 0;
    size += input;
    ElementType data;
    for (int i = 0; i < size; i++){
        cout << "Please enter a number: ";
        cin >> data;
        list(front, data);
    }
    int x;
    cout << "How many values do you want to print? ";
    cin >> x;
    print(front, x);
    deallocate(front);
}

void print(Node* nPtr, int x){
    if (nPtr == nullptr || x == 0){
        return;
    }
    else {
        cout << nPtr->data << " ";
        print(nPtr->next, x-1);
    }
}
void list(Node* &front, ElementType newData){
    // allocate Node
    Node* newNode = new Node;

    // put in the data from the user
    newNode->data = newData;

    // since the new node is going to be the last one so make the next of it to NULL
    newNode->next = nullptr;

    // if the list is empty then make the new node as the front
    if (front == nullptr){
        front = newNode;
        return;
    }

    // else traverse till the last node
    Node* last = front;
    while (last->next != nullptr){
        last = last->next;
}
    // change the next to new node
    last->next = newNode;
    return;
}
void deallocate(Node* &front){
    // create a head and set it to the first element (front) of the list
    Node* head = front;

    // create a temp node
    Node* temp;
    while (head != nullptr){ // check if head exists
        // set the second element to temp
        temp = head->next;
        // delete the first one
        delete head;
        // set the head to temp, now the first element is the temp
        head = temp;
    }
}
