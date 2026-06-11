#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> * l;
    bool isUndir;
    public : 

        Graph(int V, bool isUndir = false){
            this->V = V;
            this->isUndir= isUndir;
            l = new list<int> [V];
        }

        ~Graph(){
            delete [] l;
        }

        void addEdge(int u, int v ){
            l[u].push_back(v);
            if(isUndir){
                l[v].push_back(u);
            }
        }


        bool isCycleHelper(int src, vector<bool> &vis, vector<bool> &recPath){
            vis[src] = true;
            recPath[src] = true;

            for(int v : l[src]){
                if(!vis[v]){
                    if(isCycleHelper(v, vis, recPath)){
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

        bool isCyclic(){
            vector<bool> vis(V, false);
            vector<bool> recPath(V, false);

            for(int i=0; i<V; i++){
                if(!vis[i]){
                    if(isCycleHelper(i, vis, recPath)){
                        return true;
                    }
                }
            }

            return false;
        }
};

int main(){
    Graph graph(2);

    graph.addEdge(0,1);
    cout <<"can we complete all course(0-> no, 1-> yes) : " << !graph.isCyclic() << endl; //1

    Graph graph2(2);
    graph2.addEdge(0,1);
    graph2.addEdge(1,0);

    cout << "can we complete all course(0-> no, 1-> yes) : "<< !graph2.isCyclic() << endl; //0

    return 0;
}

// output : 
// can we complete all course(0-> no, 1-> yes) : 1
// can we complete all course(0-> no, 1-> yes) : 0

//t.c. O(V+E)
//sc O(V+E)
