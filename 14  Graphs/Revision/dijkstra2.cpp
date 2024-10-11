#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph{
public:
    int n;
    list <pair<int,int>> *l;

    Graph(int V = 2){
        n = V;
        l = new list<pair<int,int>>[n];
    }

    void addEdge(int a, int b,int w){
        l[a].push_back({b,w});
        l[b].push_back({a,w});
    }

    vector<int> dijkstra(int s){
        vector<int> res(n, INT_MAX);
        res[s]=0;
        cout<<"DJ"<<endl;
        priority_queue<pair<int,int>> dp;
        dp.push({0,s});
        while(!dp.empty()){
            int top = dp.top().second;
            int dist = dp.top().first;
            dp.pop();
            for(pair<int,int> i : l[top]){
                int currDist = i.second + dist;
                int currNode = i.first;
                cout<<currNode <<", "<< currDist<<endl;
                if(currDist<res[currNode]){
                    res[currNode] = currDist;
                    dp.push({currDist, currNode});
                }

            }
        }
        return res;
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(0,3,7);
    g.addEdge(0,2,4);
    g.addEdge(3,2,2);
    g.addEdge(3,4,3);

    vector<int> dist = g.dijkstra(0);

    for(int i : dist){
        cout<<i<<", ";
    }
    cout<<endl;

}


