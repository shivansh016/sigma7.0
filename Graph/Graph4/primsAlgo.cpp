#include<iostream>
#include<vector>
#include<list>
#include<queue>


using namespace std;

class Graph{
    int V;
    list<pair<int, int>> * l; //wt, neighbour
    bool isUndir;


    public : 

        Graph(int V, bool isUndir = true){
            this->V = V;
            this->isUndir = isUndir;
            l = new list<pair<int, int>> [V];
        }

        void addEdge(int u, int v , int wt){ //u-- v (wt)
            l[u].push_back(make_pair(v, wt));
            if(isUndir){
                l[v].push_back(make_pair(u, wt));
            }
        }

        int primsAlgo(int src){
            priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int,int>> > pq;
            int ans = 0;
            vector<bool> mstSet(V, false);
            
            pq.push(make_pair(0, src)); //wt, v

            while(!pq.empty()){
                int cost = pq.top().first;
                int u = pq.top().second;
                
                pq.pop();


                if(!mstSet[u]){
                    mstSet[u] = true;
                    ans += cost;
                    list<pair<int, int>> neighbour = l[u];
                    for(auto v : neighbour){
                        if(!mstSet[v.first]){
                            pq.push(make_pair(v.second, v.first));
                        }
                    }
                }
            }

            return ans;
        }


};

int main(){
    Graph graph(4);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);
    graph.addEdge(1, 3, 40);
    graph.addEdge(2, 3, 50);

    cout << graph.primsAlgo(0) << endl;

    return 0;
}

