#include<iostream>
#include<list>
#include<vector>
using namespace std;
bool *visited;
class Graph{
    int V;
    list<int> *l;
    public:
    Graph(int v){
        this->V = v;
        l = new list<int>[V];
    }
    void addEdge(int a, int b){
        this->l[a].push_back(b);
        this->l[b].push_back(a);
        cout<<a<<" -- "<<b<<endl;
    }
    bool dfs(int idx, int parent){
        if(visited[idx]) {
            cout<<"cycle : "<<idx<<','<<parent<<endl;
            return true;
        }
        visited[idx] = true;
        for(int child : this->l[idx]){
            if(child!=parent) {
                if(dfs(child, idx)) {
                    cout<<"found: "<<child<<" from "<< parent<<endl;
                    return true;
                }
            }
        }
        return false;
    }
};

bool contains_cycle(int k, vector<pair<int,int> > edges){
    int n=0;
    for(auto p : edges){
        n= max(max(p.first, p.second),n);
    }
    Graph g(n+1);
    visited = new bool[n+1]{false};
    //Complete this method
    for(auto p : edges){
        g.addEdge(p.first, p.second);
    }
    for(int i=0; i<n+1; i++){
            if(!visited[i]) {
                if(g.dfs(i, -1)) {
                    return true;
                }
            }
        }
    cout<<"not a cycle";
    return false;
    
    
}

int main(){
    vector<pair<int,int>> v = {{0,1},{1,2},{2,3},{4,5},{0,5},{0,4}};
    cout<< contains_cycle(4, v);
    return 0;
}