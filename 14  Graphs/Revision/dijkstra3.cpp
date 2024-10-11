#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Graph{
public:
    int n;
    list<pair<int,int>> *l;

    Graph(int V = 2){
        n=V;
        l = new list<pair<int,int>>[n];
    }

    void addEdge(int x, int y, int w){
        l[x].push_back({y,w});
        l[y].push_back({x,w});
    }

    vector<int> dijkstra(int s){
        priority_queue<pair<int,int>> pq;
        pq.push({0, s});
        vector<int> res(n, INT_MAX);
        res[s] = 0;

        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(pair<int,int> p : l[node]){
                int currNode = p.first;
                int currDist = dist + p.second;

                if(currDist<res[currNode]){
                    res[currNode] = currDist;
                    pq.push({currDist, currNode});
                }
            }
        }
        return res;
    }
    
};

int main(){
    Graph g(5);
    g.addEdge(0,1,1);
    g.addEdge(0,2,4);
    g.addEdge(0,3,7);
    g.addEdge(2,1,1);
    g.addEdge(3,2,2);
    g.addEdge(3,4,3);

    vector<int> res = g.dijkstra(4);

    for(int i : res){
        cout<<i<<", ";
    }
    cout<<endl;
}