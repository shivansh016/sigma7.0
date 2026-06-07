#include<bits/stdc++.h>
using namespace std;

 class Graph{
    int V;
    list<int> * l;
    bool isUndir; 

    public: 
        Graph(int V, bool isUndir = false){
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
                cout << i << " : ";
                list<int> neighbour = l[i];
                for(int v : neighbour){
                    cout << v << " ";
                }
                cout << endl;
            }
        }

        bool isCyclicUndirHelper(int src, vector<bool>&vis, int par){
            vis[src]= true;
            list<int> neighbour = l[src];
            for(int v : neighbour){
                if(!vis[v]){
                    if(isCyclicUndirHelper(v, vis, src)){
                        return true;
                    }
                }else{
                    if(v != par){
                        return true;
                    }
                }
            }
            return false;
        }

        bool isCyclicDirHelper(int src, vector<bool>&vis, vector<bool> & recPath){
            vis[src] = true;
            recPath[src] = true;

            list<int> neighbour = l[src];
            for(int v : neighbour){
                if(!vis[v]){
                    if(isCyclicDirHelper(v, vis, recPath)){
                        return true;
                    }
                }else{
                    if(recPath[v] == true){
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
            
            if(isUndir){
                for(int i=0; i<V; i++){
                    if(!vis[i]){
                        if(isCyclicUndirHelper(i, vis, -1)){
                            return true;
                        }
                    }
                }
                return false;
                
            }else{
                for(int i=0; i<V; i++){
                    if(!vis[i]){
                        if(isCyclicDirHelper(i, vis, recPath)){
                            return true;
                        }
                    }
                }
                return false;
            }
        }

        bool isBipartite(){
            if(!isCyclic()){
                return true; //acyclic are always bipartite.
            }else{
                //count the nodes in  the cycle 
                //nodeCountinCycle =>odd = > return false
                //nodeCountinCycle => even = > return true.


            }
        }


 };

int main(){

}