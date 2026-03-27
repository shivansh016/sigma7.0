#include<iostream>
#include<queue>
#include<string>
using namespace std;


// all the stl functions are :
// push(), pop(), top(), empty() , swap(), size(), emplace() .. only these functions in the pq stl.
int main(){
    priority_queue<int> pq;

    pq.push(2);
    pq.push(5);
    pq.push(6);
    pq.push(9);

    cout << "size : " <<pq.size() << endl;
    cout << pq.empty() << endl; // 0
    while(!pq.empty()){
        cout << pq.top() << endl; // 9 6 5 2 (default order is of maxHeap in the stl...)
        pq.pop();
    }

    priority_queue<int> pq2;

    pq2.push(34);
    pq2.push(44);
    pq.swap(pq2);
    cout << endl << "after swapping with pq2 :" << endl;
    while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    }

    cout << pq2.empty() <<endl;

    // MIN heap i.e. priority queue using the min element priority.. syntax and implementation..
    cout << "---------------------------------------------------------- " << endl;
    priority_queue <int> pq3;
    priority_queue< int, vector<int> , greater<int>> pq4;

    pq3.push(38);
    pq3.push(32);
    pq3.push(6);
    pq3.push(36);

    cout << "pq3 elements (default==> so max is prior..)" << endl;
    while(!pq3.empty()){
        cout << "top : " << pq3.top() << endl;
        pq3.pop() ;
    }

    pq4.push(38);
    pq4.push(32);
    pq4.push(6);
    pq4.push(36);
cout << "pq4 elements(min is prior ) :" << endl;
    while(!pq4.empty()){
        cout << "top : " << pq4.top() << endl;
        pq4.pop();
    }

    //Similarly this can pr implementation can be done for strings as well 
    priority_queue<string> pqs;

    pqs.push("apna college");
    pqs.push("not now");
    pqs.push("where are you ?");
    pqs.push("i can't");

    priority_queue<string, vector<string>, greater<string>> pqsInMin ;
    pqsInMin.push("apna college");
    pqsInMin.push("not now");
    pqsInMin.push("where are you ?");
    pqsInMin.push("i can't ");

    while(!pqs.empty()){
        cout << pqs.top() << endl;
        pqs.pop();
    }
cout << endl << "pqsInMin where min element is prior : " << endl;
    while(!pqsInMin.empty()){
        cout << pqsInMin.top() << endl;
        pqsInMin.pop();
    }

    return 0;

}

// Output : ....>
// size : 4
// 0
// 9
// 6
// 5
// 2

// after swapping with pq2 :
// 44
// 34
// 1
// ----------------------------------------------------------
// pq3 elements (default==> so max is prior..)
// top : 38
// top : 36
// top : 32
// top : 6
// pq4 elements(min is prior ) :
// top : 6
// top : 32
// top : 36
// top : 38
// where are you ?
// not now
// i can't
// apna college

// pqsInMin where min element is prior :
// apna college
// i can't
// not now
// where are you ?