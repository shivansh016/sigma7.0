#include<iostream>
#include<list>
#include<vector>
#include<utility>

using namespace std;

// class Graph{
//     int V;
//     list<pair<int, int>> *l;
//     public:
//         Graph(int V){
//             this->V = V;
//             l = new list<pair<int,int>> [V];
//         }

//         void addEdge(int u, int v, int wt){
//             l[u].push_back(make_pair(v, wt));
//             l[v].push_back(make_pair(u, wt));
//         }

//         void print(){
//             for(int u=0; u<V; u++){
//                 list<pair<int, int>> neighbour = l[u];
//                 cout << u << " : ";

//                 for(pair<int,int> p : neighbour){
//                     cout << "(" << p.first << "," << p.second << ")" << " ";
//                 }
//                 cout << endl;
//             }
//         }
// };

// int main(){
//     Graph graph(5);

//     graph.addEdge(0,1,5); //u,v, wt
//     graph.addEdge(1,2,1);
//     graph.addEdge(1,3,3);
//     graph.addEdge(2,3,1);
//     graph.addEdge(2,4,2);

//     graph.print();
// //Output:

// // 0 : (1,5) 
// // 1 : (0,5) (2,1) (3,3) 
// // 2 : (1,1) (3,1) (4,2) 
// // 3 : (1,3) (2,1) 
// // 4 : (2,2) 

//     return 0;
// }

class Graph{
    int V;
    list<int> * l;

    public:
        Graph(int V){
            this->V = V;
            l = new list<int> [V]; // V size ki list bana di
        }

        void addEdge(int u, int v){// adding an edge ... u--v (undirected) 
/*agar directed hota to sirf 'u' me 'v' ko push_back karte bas. */

            l[u].push_back(v);
            l[v].push_back(u);
        }

        void print(){
            for(int u = 0; u<V; u++){//0,1,2,3,4
                list<int> neighbour = l[u];
                cout << u << " : " ;
                for(int v: neighbour){
                    cout << v << " ";
                }
                cout << endl;
            }
        }
};

int main(){

    Graph graph(5);

    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    graph.addEdge(2,4);

    graph.print();
//OUtput 

// 0 : 1 
// 1 : 0 2 3 
// 2 : 1 3 4 
// 3 : 1 2 
// 4 : 2 

    return 0;
}
