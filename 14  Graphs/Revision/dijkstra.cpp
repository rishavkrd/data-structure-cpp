#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <map>

using namespace std;

class Node{
public:
    int val;
    list<pair<int,int>> neigh;  // {node, weight}

    Node(int n){
        val = n;
    }
};

class Graph{
public:
    map<int, Node*> m;
    int v;
    bool undir;
    Graph(int V, bool setUndir=true){
        v = V;
        undir = setUndir;
        for(int i=0; i<v; i++){
            m[i] = new Node(i);
        }
    }
    void addEdge(int a, int b, int weight){
        m[a]->neigh.push_back({b,weight});
        if(undir){
            m[b]->neigh.push_back({a, weight});
        }
    }
    void printGraph(){
        for(auto vertex : m){
            Node* node = vertex.second;
            cout<<"Node: "<<node->val<<" -> ";
            for(auto np : node->neigh){
                cout<<np.first<<"("<<np.second<<"), ";
            }
            cout<<endl;

        }
    }
    vector<int> dijkstra(int source){
        vector<int> res = vector<int>(v, INT_MAX);
        res[0] = 0;
        set<pair<int,int>> s;
        s.insert({0,source});

        while(!s.empty()){
            auto front = s.begin();
            int currentNode = front->second;
            int currentDistance = front->first;
            s.erase(front);

            for(auto np : m[currentNode]->neigh){
                int distance = currentDistance + np.second;
                int node = np.first;
                if(res[node]>distance){
                    res[node] = distance;
                    // if(s.find({res[node], node}) != s.end()){
                    //     s.erase({res[node], node});
                    // }
                    s.insert({distance, node});
                }
            }
            
        }

        for(int i=0;i<res.size();i++){
            cout<<endl<<"Distance to "<<i<<" is "<<res[i];
        }
        return res;
    }
};

int main(){
    Graph* g = new Graph(5);
    g->addEdge(0,1,1);
    g->addEdge(1,2,1);
    g->addEdge(0,2,4);
    g->addEdge(0,3,7);
    g->addEdge(2,3,2);
    g->addEdge(3,4,3);

    g->printGraph();

    g->dijkstra(0);

    return 0;
}