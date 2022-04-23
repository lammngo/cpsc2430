#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_SIZE = 6;

template <typename T>
void enqueue(T* doubleQueue, int &size);
template <typename T>
T dequeue(T* doubleQueue, int &size);
template <typename T>
void print(T* doubleQueue, int size);

int main() {
    float* doubleQueue = new float[MAX_SIZE]; //Set the initial size of the array
    float input;
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
        cout << endl;
        cout << "Do you want to enqueue(e), dequeue(d), or quit (q)? ";
        cin >> charInput;
        // if enqueue
        if (charInput == 'e') {
            enqueue(doubleQueue, size);
            print(doubleQueue, size);
        }
        // if dequeue
        if (charInput == 'd') {
            float a = dequeue(doubleQueue, size);
            if (a == 0){
                cout << "Nothing to dequeue" << endl;
            } else {
                cout << "The dequeue value is: " << a << endl;
            }
        }
    }
    srand(time(0));
    vector<int> data{};
    for (int i = 0; i < 5; i++){
        //cout << 1 + (rand()%9) << " " << endl;
        data.push_back(1 + (rand()%100));
    }
    cout << endl << "Creating a vector of 5 random integers: " << endl;
    for (int x : data)
        cout << x << " ";
    cout << endl;
    cout << endl << "Doubling each value using an iterator." << endl;
    cout << endl << "After doubling: " << endl;
    vector<int>::iterator it;
    for (it = data.begin(); it != data.end(); it++) {
        //(*it) = (*it) * 2;
        replace(data.begin(), data.end(), *it, *it * 2);
        cout << *it << " ";
    }
}
template <typename T>
void enqueue(T* doubleQueue, int& size){
    // check if the queue is empty
    if (size == 0) {
        T input;
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
template <typename T>
T dequeue(T* doubleQueue, int& size){
    T returnValue = doubleQueue[0];
    if (size > 0) { // remove the first element
        for (int i = 0; i < size; i++){
            doubleQueue[i] = doubleQueue[i+1];
        }
        size--;
    }
    return returnValue;
}
template <typename T>
void print(T* doubleQueue, int size){
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
