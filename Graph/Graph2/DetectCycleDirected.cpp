#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int>*l;
    bool isUndir;

    public:
        Graph(int V, bool isUndir = true){
            this->V = V;
            l = new list<int> [V];
            this->isUndir = isUndir;
        }

        void addEdge(int u, int v){
            l[u].push_back(v);
            if(isUndir){// matlab jab undirected ho tabhi dono nodes ko connect karenge.
                l[v].push_back(u);
            }
        }

        void print(){
            for(int i=0; i<V; i++){
                cout << i << " : ";
                list<int> neighbour = l[i];
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
                for(int i=0; i<V; i++){
                    if(!vis[i]){
                        dfsHelper(i, vis);
                    }
                }
               
                cout << endl;
            }

        bool isCycleDirHelper(int src, vector<bool>& vis, vector<bool> &recPath){
            vis[src] = true;
            recPath[src] = true;

            list<int> neighbour = l[src];

            for(int v : neighbour){
                if(!vis[v]){
                    if(isCycleDirHelper(v, vis, recPath)){
                        return true;
                    }
                }else{
                    if(recPath[v]){
                        return true;
                    }
                }
            }

            recPath[src] = false;
            return false;


        }

        bool isCycleDir(){
            vector<bool> vis(V, false);
            vector<bool> recPath(V, false);
            for(int i=0; i<V; i++){
                if(!vis[i]){
                    if(isCycleDirHelper(i, vis, recPath)){
                        return true;
                    }
                }
            }
            return false;
        }

};
int main(){
    Graph graph(4, false);

    graph.addEdge(1,0);
    graph.addEdge(0,2);
    graph.addEdge(2,3);
    graph.addEdge(3,0);

    graph.print();
    graph.dfs();

    cout << "cycle exist(0->no, 1->yes) : " << graph.isCycleDir();
    return 0;
}

//Output :

// 0 : 2 
// 1 : 0 
// 2 : 3 
// 3 : 0 
// 0 2 3 1 
// cycle exist(0->no, 1->yes) : 1