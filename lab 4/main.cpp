#include <iostream>

using namespace std;

const int CAPACITY = 13;

void goUp(int arr[], int index){
    int parent = (index-1)/2;
    if (index != 0 && arr[index] < arr[parent]) {
        int temp;
        temp = arr[index];
        arr[index] = arr[parent];
        arr[parent] = temp;
        goUp(arr, parent);
    }
}

void insert(int arr[], int val, int &currentSize){
    if (currentSize < CAPACITY){
        arr[currentSize] = val;
        goUp(arr, currentSize);
        currentSize++;
    }
}
void printArray(int arr[], int currentSize){
    cout << "heap = " << "[ -, ";
    for (int i = 1; i < CAPACITY-1; i++) {
        if (i < currentSize) {
            cout << arr[i] << ", ";
        } else {
            cout << "_ , ";
        }
    }
    cout << "_ ]" << endl;
}

void goDown(int arr[], int currentSize, int index){
    int smallest = index;
    //cout << "index: " << smallest << endl;
    int left = 2 * index;
    //cout << "left: " << left << endl;
    //cout << "arr[left]: " << arr[left] << endl;
    int right = 2 * index + 1;
    //cout << "right: " << right << endl;
    //cout << "arr[right]: " << arr[right] << endl;
    if (left < currentSize && arr[left] < arr[smallest]){
        smallest = left;
        //cout << "arr smallest: " << arr[smallest] << endl;
    }
    if (right < currentSize && arr[right] < arr[smallest]){
        smallest = right;
        //cout << "smallest: " << smallest << endl;
    }
    if (smallest != index){
        int temp;
        temp = arr[index];
        //cout << "temp: " << temp << endl;
        arr[index] = arr[smallest];
        //cout << "arr[index] " << arr[index] << endl;
        arr[smallest] = temp;
        //cout << "arr[smallest] " << arr[smallest] << endl;
        cout << "Moving child = " << arr[index] << " up" << endl;
        goDown(arr, currentSize, smallest);
    }
}

int deleteMin(int arr[], int &currentSize){
    if (currentSize <= 0){
        return arr[currentSize];
    }
    if (currentSize == 1){
        currentSize--;
        return arr[1];
    }
    int root = arr[1];
    //cout << "root: " << root << endl;
    arr[1] = arr[currentSize-1];
    //cout << "a[1]= " << arr[1] << endl;
    currentSize--;
    goDown(arr, currentSize, 1);
    cout << root << " is deleted from the heap." << endl;
    return root;
}

int main() {
    int currentSize = 1;
    int arr[13];
    int input[] = {0, 2, 6, 83, 7, 76, 20, 100, 86, 90};
    for (int i = 0; i < 10; i++){
        insert(arr, input[i], currentSize);
    }
    cout << endl;
    printArray(arr, currentSize);
    cout << endl;
    //cout << "current size: " << currentSize << endl;
    int num;
    cout << "How many values should we remove? ";
    cin >> num;
    for (int i = 0; i < num; i++){
        cout << endl;
        deleteMin(arr, currentSize);
    }
    cout << endl;
    cout << "End of Lab 4. Have a nice day!" << endl;
}
