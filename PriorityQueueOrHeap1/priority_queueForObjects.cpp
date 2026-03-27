#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

// class Student{
//     public:
//         string name;
//         int marks;

//         Student(string name, int marks){
//             this->name = name;
//             this->marks = marks;
//         }
// };


// this will give error as the priority queue not knows On which basis it has to sort the elements of the Student class...... So we need to do "Operator Overloading ..."
// int main(){
//     priority_queue<Student> pq;

//     pq.push(Student("Aman", 80));
//     pq.push(Student("Shraddha", 95));
//     pq.push(Student("chetan", 50));

//     while(!pq.empty()){
//         cout << " name : " << pq.top().name << ", " << "marks : " << endl;
//         pq.pop();
//     }
//     return 0;
// }


// Operator overloaded class

class Student{ // overload < 
    public:
        string name;
        int marks;

        Student(string name, int marks){
            this->name = name;
            this->marks = marks;
        }

        bool operator < (const Student &obj) const {
            return this->marks < obj.marks; // the < symbol represents the ascending order and marks is the basis
            // return this->name > obj.name; // will sort in ascending on basis of the name..
        }
};

int main(){
    priority_queue<Student> pq;

    pq.push(Student("aman", 80));
    pq.push(Student("bhumik", 95));
    pq.push(Student("chetan", 50));

    while(!pq.empty()){
        cout << " name : " << pq.top().name << ", " << "marks : " << pq.top().marks << endl;
        pq.pop();
    }
    return 0;
}


// Output => shows that details are sorted on the basis of the marks (descending order// max Heap)..

//  name : Shraddha, marks : 95
//  name : Aman, marks : 80
//  name : chetan, marks : 50


// sorted in ascending order(min heap ) on the basis of the name.
//  name : aman, marks : 80
//  name : bhumik, marks : 95
//  name : chetan, marks : 50