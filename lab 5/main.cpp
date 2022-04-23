#include <iostream>

using namespace std;

//size = 10 -> 8 collisions
//size = 12 -> 7 collisions
//size = 13 -> 3 collisions

//if we choose the size 10, it would cause the most collisions because any number mod 10
//will be the last digit. In case we choose a non-prime and even number, for ex, size 12,
//it still causes a big amount of collisions because the results got repeated multiple times.
//Base on the collisions that we got from choosing size 13, we can tell that one of the good ways
//to prevent collision is choosing a prime number.

class Course{
private:
    string title;
    int courseNo;
public:
    Course();
    Course(string titleArr, int keyArr);
    int hashFunc(int key);
    bool addCourse(Course arr[], string t, int key);
    void print(Course arr[]);
};

const int MAX_SIZE = 7;

int main()
{
    //create an array
    Course arr[15];
    //create a hash
    Course hash;
    int arrSize = 15, count = 0;
    bool isEmpty;

    string titleArr [] = {"Introduction to Computer Science",
                          "Data-Driven Problem Solving & Programming", "Programming and Data Types",
                          "Programming and Problem Solving I ", "Programming and Problem Solving II",
                          "Data Structures", "Computer Organization", "Foundations of Computer Science",
                          "Object-Oriented Development", "Fundamentals of Databases",
                          "Languages and Computation", "Computing Systems",
                          "Design and Analysis of Algorithms", "Software as a Service",
                          "Mobile Software Development"};

    int keyArr [] = {1000,1220,1230,1420,1430,2430,2500,2600,3200,3300,
                     3400,3500,4100,4240,4250};

    for (int i = 0; i < arrSize; i++){
        //if isEmpty is true, then add the courses
        isEmpty = hash.addCourse(arr, titleArr[i], keyArr[i]);
        //else, increment the collision counter
        if (!isEmpty)
            count ++;
    }
    cout << "There were " << count << " collisions." << endl;
    cout << endl;
    hash.print(arr);

    return 0;
}
Course ::Course() {
    //set initial value for title and courseNo
    title = " ";
    courseNo = 0;
}
Course ::Course(string titleArr, int keyArr) {
    //construct a course object
    title = titleArr;
    courseNo = keyArr;
}

int Course ::hashFunc(int key){
    int divide;
    int mod;
    int sum;
    int index;
    mod = key % 100;
    //cout << "mod: " << mod << endl;
    divide = key/100;
    //cout << "divide: " << divide << endl;
    sum = mod + divide;
    //cout << "sum: " << sum << endl;
    index = sum % MAX_SIZE;
    //cout << "index: " << index << endl;
    return index;
}

bool Course ::addCourse(Course arr[], string t, int key){
    bool isEmpty = true;
    //find a hashed index of the key/courseNo
    int index = hashFunc(key);
    //create newCourse object
    Course newCourse(t, key);
    //if the title is not in the array then add the title and the key in
    if (arr[index].title == " "){
        arr[index].title = t;
        arr[index].courseNo = key;
    } else {
        isEmpty = false;
        cout << "Collision at index " << index << " for key " << key << endl;
    }
    return isEmpty;
}

void Course ::print(Course arr[]) {
    for (int i = 0; i < MAX_SIZE; i++){
        cout << "schedule[" << i << "]-------------" << endl;
        cout << "Course: " << arr[i].courseNo << endl;
        cout << "Title: " << arr[i].title << endl;
        cout << endl;
    }
}
