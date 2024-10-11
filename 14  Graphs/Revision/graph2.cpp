#include<iostream>
#include<vector>
#include<set>
#include<list>

using namespace std;

class Graph{
public:
    int n;
    list <int> *l;
    bool undirected;

    Graph(int V=5, bool ud = true){
        n = V;
        undirected = ud;
        l = new list<int>[n];
    }
    void addEdge(int a, int b){
        l[a].push_back(b);
        if(undirected){
            l[b].push_back(a);
        }
    }

    bool dfs_cycle_undirected(int n, int p, set<int> &s){
        if(s.find(n) != s.end()){
            cout<<"cycle found"<<n<<"->"<<p<<endl;
            return true;
        }
        s.insert(n);
        for(int node : l[n]){
            if(node!=p){
                if(dfs_cycle_undirected(node, n, s)) return true;
            }
        }
        return false;
    }
    bool cycle_undirected(){
        set<int> s;
        for(int i=0; i<n; i++){
            if(s.find(i)==s.end()){
                if(dfs_cycle_undirected(i, -1, s)){
                    return true;
                }
            }

        }
        return false;
    }

    bool dfs_cycle_directed(int n, vector<bool> &dp, vector<bool>& visited){
        if(visited[n]){
            return dp[n];
        }
        cout<<n<<endl;
        bool res = false;
        visited[n] = 1;
        for(int node : l[n]){
            if(visited[node]){
                if(dp[node]) cout<<"cycle at "<<node<<endl;
                return dp[node] = 1;
            }
            res = res | dfs_cycle_directed(node, dp, visited);
        }
        
        return dp[n] = res;
    }

    bool cycle_directed(){
        vector<bool> dp (n, 1);
        vector<bool> visited(n, 0);

        for(int i=0; i<n; i++){
            if(!visited[i]){
                if(dfs_cycle_directed(i, dp, visited)) return true;

            }
        }
        return false;
    }
};


int main(){
    Graph* g = new Graph(9, false);

    g->addEdge(0,1);
    g->addEdge(1,2);
    // g->addEdge(3,2);
    g->addEdge(2,3);
    g->addEdge(3,0);
    // g->addEdge(5,4);
    g->addEdge(0,4);
    g->addEdge(0,5);
    // Isolated cycle
    g->addEdge(6,7);
    g->addEdge(7,8);
    // g->addEdge(8,6);

    // g->printGraph();
    // g->bfs(1);
    // int inp;
    // cin >> inp;
    // g->shortestDistance(1, inp);
    // cout<<endl<<"DFS: "<<endl;
    // g->dfs(1);

    bool cycle = g->cycle_directed();
    cout<<"Directed cycle: "<<cycle<<endl;
    
    

    return 0;
}