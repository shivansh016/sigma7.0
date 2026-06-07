#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<queue>

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

        void dfsHelper(int src, vector<bool> &vis){
            vis[src] = true;
            cout << src << " ";
            list<int> neighbour = l[src];

            for(int v : neighbour){
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

        void bfsHelper(int src, vector<bool> & vis){
            queue<int> q;
            q.push(src);
            vis[src] = true;

            while(!q.empty()){
                int curr = q.front();
                cout << curr << " ";
                q.pop();
                list<int> neighbour = l[curr];
                for(int v : neighbour){
                    if(!vis[v]){
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
            

        }

        void bfs(){
            vector<bool> vis(V, false);
            for(int i=0; i<V; i++){
                if(!vis[i]){
                    bfsHelper(i, vis);
                }
            }
            cout << endl;
            
        }

        void allPathsHelper(int src, int dest, vector<bool> & vis, string & path){//using dfs
            if(src == dest){
                cout << path << dest << endl;
                return;
            }

            vis[src] =true;
            // path.push_back(src); this adds the ascii value of the src
            path += to_string(src);
            list<int> neighbour = l[src];

            for(int v : neighbour){
                if(!vis[v]){
                    allPathsHelper(v, dest, vis, path);
                }
            }

            // path = path.substr(0, path.size()-1); //remvoes the last digit only what if we had number of more than 1 digit ... so use pop_back()
            path.pop_back();
            vis[src] = false;
        }

        void allPaths(int src, int dest){
            string ans = "";
            vector<bool> vis(V, false);
            allPathsHelper(src, dest, vis, ans);
        }

};

int main(){
    Graph graph(6);


    graph.addEdge(0,3);
    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.addEdge(4,0);
    graph.addEdge(4,1);
    graph.addEdge(5,2);
    graph.addEdge(5,0);

    graph.print();

    cout << endl;

    graph.bfs();

    cout << endl;

    graph.dfs(); 

    cout << endl;

    graph.allPaths(5,1);

    return 0;
}

//Output :

// 0 : 3 
// 1 : 
// 2 : 3 
// 3 : 1 
// 4 : 0 1 
// 5 : 2 0 

// 0 3 1 2 4 5 

// 0 3 1 2 4 5 

// 5231
// 5031