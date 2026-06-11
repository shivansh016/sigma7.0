#include<iostream>
#include<vector>
#include<stack>
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

        void topoSortDfsHelper(int src, vector<bool>& vis, stack<int>& s){
            vis[src] = true;

            for(int v : l[src]){
                if(!vis[v]){
                    topoSortDfsHelper(v, vis, s);
                }
            }
            s.push(src);
        }

        vector<int> topoSort(){
            vector<bool> vis(V, false);
            stack<int> s;
            vector<int> ans;


            for(int i=0; i<V; i++){
                if(!vis[i]){
                    topoSortDfsHelper(i, vis, s);
                }
            }

            while(!s.empty()){
                ans.push_back(s.top());
                s.pop();
            }

            return ans;
        }
};

void CourseScheduler(Graph &graph){
    if(graph.isCyclic()){
        cout << "empty vector !" ;
    }else{
        vector<int> ans = graph.topoSort();
        for(int i=0; i<ans.size(); i++){
            cout << ans[i] << " "; 
        }
    }
    cout << endl;
}

int main(){
    Graph graph1(4);

    graph1.addEdge(1,0);
    graph1.addEdge(3,0);
    graph1.addEdge(3,1);
    graph1.addEdge(3,2);

    CourseScheduler(graph1);

    Graph graph2(5);

    graph2.addEdge(1,0);
    graph2.addEdge(3,0);
    graph2.addEdge(3,1);
    graph2.addEdge(3,2);
    graph2.addEdge(2,3);
    graph2.addEdge(4,3);

    CourseScheduler(graph2);

    return 0;
}

//OUtput :
// 3 2 1 0 
// empty vector !

//t.c. O(V+E)
//s.c. O(V+E)