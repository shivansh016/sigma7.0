#include<iostream>
#include<stack>
#include<vector>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> * l;
    bool isUndir;

        public: 
            Graph(int V, bool isUndir= false){
                this->V = V;
                l = new list<int> [V];
                this->isUndir = isUndir;
            }

            void addEdge(int u, int v){
                l[u].push_back(v);
                if(isUndir){
                    l[v].push_back(u);
                }
            }

            void print(){
                for(int i=0; i<V; i++){
                    cout << i << " : " ;
                    for(int v : l[i]){
                        cout << v << " ";
                    }
                    cout << endl;
                }
            }

            void dfsHelper(int src, vector<bool> & vis, stack<int> & s){
                vis[src] = true;
                for(int v : l[src]){
                    if(!vis[v]){
                        dfsHelper(v, vis, s);
                    }
                }
                s.push(src);
            }

            stack<int> TopologicalDfs(){
                vector<bool> vis(V, false);
                stack<int> s;
                for(int i=0; i<V; i++){
                    if(!vis[i]){
                        dfsHelper(i, vis, s);
                    }
                }

                return s;
            }

};

int main(){
    Graph graph(6, false);

    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.addEdge(4,1);
    graph.addEdge(4,0);
    graph.addEdge(5,0);
    graph.addEdge(5,2);

    graph.print();
cout << "topological sorting  : \n";
    stack<int> s = graph.TopologicalDfs();
    while(!s.empty()){
        cout<< s.top() << " ";
        s.pop();
    }

    return 0;

}

// 0 : 
// 1 : 
// 2 : 3 
// 3 : 1 
// 4 : 1 0 
// 5 : 0 2 
// topological sorting  : 
// 5 4 2 3 1 0 