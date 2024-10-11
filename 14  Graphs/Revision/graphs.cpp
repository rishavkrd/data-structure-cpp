#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<unordered_set>

using namespace std;

class Node{
public:
    int val;
    list<int> neigh;

    Node (int v){
        val = v;
    }
};

class Graph{
public:
    map<int, Node*> m;
    bool undir;

    Graph(int n, bool setUndir = true){
        this->undir = setUndir;
        for(int i=0;i<n;i++){
            m[i] = new Node(i);
        }
    }
    void addEdge(int a, int b){
        m[a]->neigh.push_back(b);
        if(undir){
            m[b]->neigh.push_back(a);
        }
    }
    void printGraph(){
        for(auto mapItem : m){
            Node* node = mapItem.second;
            cout<<"Node: "<<node->val <<" : ";
            for(auto element : node->neigh){
                cout<< element<<", ";
            }
            cout<<endl;
        }
    }
    void bfs(int start){
        queue<int> q;
        unordered_set<int> visited;       //Unlike Trees, we have back to parent and overlapping pointers to same node.
        visited.insert(start);
        q.push(start);
        cout<<"BFS: "<<endl;
        while(!q.empty()){
            int current = q.front();
            q.pop();
            
            cout<<current<<", ";
            for(auto val : m[current]->neigh){
                if(visited.find(val) == visited.end()){
                    q.push(val);
                    visited.insert(val);
                }
            }
        }
    }
unordered_set<int> visited_dfs;
    void dfs(int start){
        if(visited_dfs.find(start) != visited_dfs.end()){
            return;
        }
        visited_dfs.insert(start);
        cout<<start<<", ";
        for(auto val : m[start]->neigh){
            if(visited_dfs.find(val) == visited_dfs.end()){
                dfs(val);
            }
        }

    }
    
    void shortestDistance(int start, int end){
        queue<int> q;
        unordered_set<int> visited;

        q.push(start);
        q.push(-1);
        visited.insert(start);

        int level = 0;

        while(!q.empty() && q.front()!=end){
            int current = q.front();
            q.pop();
            if(current == -1){
                if(!q.empty()){
                    level++;
                    q.push(-1);
                }
                continue;
            }
            for(auto val : m[current]->neigh){
                if(visited.find(val) == visited.end()){
                    q.push(val);
                    visited.insert(val);
                }
            }
        }
        cout<<endl<<"Distance: "<<level;
    }


unordered_set<int> cycle_visited;
    bool hasCycle(int n, int parent){
        cout<<endl<<"visiting: "<<n<<" parent: "<<parent;
        cycle_visited.insert(n);
        bool res = false;
        for(auto val: m[n]->neigh){
            if(val != parent){
                if(cycle_visited.find(val) != cycle_visited.end()){
                    cout<<" The cycle point: "<<val;
                    return true;
                }
                
                res = res | hasCycle(val, n);
                cout<<" cycle found: "<<res;
            }
        }
        return res;
    }
vector<bool> dCD = vector<bool>(10,true);
unordered_set<int> dvisited;
    bool directedCycleDetection(int idx){
        dvisited.insert(idx);
        bool res=false;
        for(auto node : m[idx]->neigh){
            if(dvisited.find(node)!=dvisited.end()){
                res = res | dCD[node];
            } else{
                res = res | directedCycleDetection(node);
            }
        }
        return dCD[idx] = res;
    }
unordered_set<int> cdSet;
unordered_set<int> pvisited;
    bool prateekCycleDetection(int idx){
        cdSet.insert(idx);
        pvisited.insert(idx);
        bool res = false;
        for(auto node : m[idx]->neigh){
            if(cdSet.find(node)!=cdSet.end()){
                cout<<"found backedge: "<<idx<<"->"<<node;
                return true;
            }
            res = res | prateekCycleDetection(node);
        }
        cdSet.erase(idx);
        return res;
    }
    
};




int main(){
    Graph* g = new Graph(9, false);

    g->addEdge(1,2);
    // g->addEdge(3,2);
    g->addEdge(0,1);
    g->addEdge(2,3);
    // g->addEdge(3,0);
    g->addEdge(5,4);
    g->addEdge(0,4);
    g->addEdge(0,5);
    // Isolated cycle
    g->addEdge(6,7);
    g->addEdge(7,8);
    g->addEdge(8,6);


    g->printGraph();
    // g->bfs(1);
    // int inp;
    // cin >> inp;
    // g->shortestDistance(1, inp);
    // cout<<endl<<"DFS: "<<endl;
    // g->dfs(1);

    bool cycle = g->hasCycle(1,-1);
    // bool cycle = false;
    // for(int i=0; i<6;i++){
    //     if(g->pvisited.find(i)==g->pvisited.end()){
    //         cycle = cycle | g->prateekCycleDetection(i);
    //         cout<<endl<<"Has Cycle: "<<cycle;
    //     }
        
    // }
    cout<<endl<<"Finall does it have a Cycle: "<<cycle;
    

    return 0;
}