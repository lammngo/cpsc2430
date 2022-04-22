#include <iostream>

using namespace std;

typedef int ElementType;
const int MAX_SIZE = 6;

void enqueue(ElementType* doubleQueue, int &size);
ElementType dequeue(ElementType* doubleQueue, int &size);
void print(ElementType* doubleQueue, int size);

int main() {
    ElementType* doubleQueue = new ElementType[MAX_SIZE]; //Set the initial size of the array
    ElementType input;
    int size = 0;
    do {
        cout << "Welcome! Please enter a positive value: "; //ask the user for a positive value to add to the queue
        cin >> input;
    }
    while (input < 0);
    doubleQueue[0] = input;
    size++;
    char charInput;
    while (charInput != 'q') {
        // ask if the user wants to enqueue, dequeue, or quit
        cout << "Do you want to enqueue(e), dequeue(d), or quit (q)? ";
        cin >> charInput;
        // if enqueue
        if (charInput == 'e') {
            enqueue(doubleQueue, size);
            print(doubleQueue, size);
        }
        // if dequeue
        if (charInput == 'd') {
            int a = dequeue(doubleQueue, size);
            if (a == 0){
                cout << "Nothing to dequeue" << endl;
            } else {
                cout << "The dequeue value is: " << a << endl;
            }
        }
    }
}
void enqueue(ElementType* doubleQueue, int& size){
    // check if the queue is empty
    if (size == 0) {
        ElementType input;
        cout << "Please enter a positive value: ";
        cin >> input;
        doubleQueue[0] = input;
        size++;
    } else if (size > 0 && size < MAX_SIZE){ // add elements in the queue
        doubleQueue[size] = doubleQueue[size - 1] * 2;
        cout << "inserted " << doubleQueue[size] << endl;
        size++;
    } else { // if full
        cout << "Max size reached." << endl;
    }
}
ElementType dequeue(ElementType* doubleQueue, int& size){
    int returnValue = doubleQueue[0];
    if (size > 0) { // remove the first element
        for (int i = 0; i < size; i++){
            doubleQueue[i] = doubleQueue[i+1];
        }
        size--;
    }
    return returnValue;
}
void print(ElementType* doubleQueue, int size){
    cout << "Current queue: ";
    for (int i = 0; i < size; i++){ // print the last one without comma
        if (i == size - 1){
            cout << doubleQueue[i];
        } else {
            cout << doubleQueue[i] << ", "; // print the rest of the queue with trailing comma
        }
    }
    cout << endl;
}
