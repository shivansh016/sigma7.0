#include<iostream>
#include<vector>
#include<list>


using namespace std;

class Graph{
    
    int V;
    list<int>* l;

        public: 
            Graph(int V){
                this->V = V;
                l = new list<int> [V];
            }

            void addEdge(int u, int v){
                l[u].push_back(v);
                l[v].push_back(u);
                
            }

            void print(){
                for(int u = 0; u<V; u++){
                    cout << u  << " : ";
                    list<int> neighbour = l[u];
                    for(int v : neighbour){
                        cout << v << " ";
                    }
                    cout << endl;
                }
            }

            void dfsHelper(int src, vector<bool> &vis){
                cout << src << " " ;
                vis[src] = true;

                list<int> neibhgbour = l[src];

                for(int v : neibhgbour){
                    if(!vis[v]){
                        dfsHelper(v, vis);
                    }
                }
                
            }

            void dfs(){
                vector<bool> vis(V, false);
                dfsHelper(0, vis);
                cout << endl;
            }

            bool isCycleHelper(int src, vector<bool>&vis, int par){
                vis[src] = true;
                list<int> neighbour = l[src];
                for(int v : neighbour){
                    if(!vis[v]){
                        if(isCycleHelper(v, vis, src)){
                            return true; // baad ke kisi node pe agar cycle exist kare then we return true..
                        }
                    }else{//already visited //apne hi node pe mil jaye cycle.
                        if(v != par){
                            return true;
                        }
                    }
                }
                return false;
            }

            bool isCycleUndir(){
                vector<bool> vis(V,false);
                return isCycleHelper(0, vis, -1);
            }

};

int main(){
    Graph graph(5);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(0,3);
    graph.addEdge(1,2);
    graph.addEdge(3,4);

    graph.print();

    graph.dfs();

    cout << "cycle exist(0->no, 1->yes) : " << graph.isCycleUndir();

    return 0;

}

//Camel Notation : first letter ->small , any other word later ->first letter (capital)

//Output :

// 0 : 1 2 3 
// 1 : 0 2 
// 2 : 0 1 
// 3 : 0 4 
// 4 : 3 
// 0 1 2 3 4 
// cycle exist(0->no, 1->yes) : 1