#include<iostream>
#include<list>
#include<queue>
#include<unordered_set>
#include<climits>
using namespace std;


class Graph{
	int V;
	list<int> *l;
public:
	Graph(int v){
		V = v;
		l = new list<int>[v];
	}

	void addEdge(int a, int b, bool undir = true){
		l[a].push_back(b);
		if(undir){
			l[b].push_back(a);
		}
	}
	void printAdjList(){

		for(int i=0;i<this->V;i++){
			cout<<i<<" : ";
			for(auto j : l[i]){
				cout<<j<<"-->";
			}
			cout<<endl;
		}
		
	}
	int bfs(int source, int dest=-1){
	 	unordered_set<int> visited;
	 	int dist[this->V] = {0};
	 	int parent[this->V] = {-1};
	 	queue<int> q;
	 	q.push(source);
	 	q.push(-1);
	 	parent[source] = source;
	 	visited.insert(source);
	 	// int d=1;
	 	while(!q.empty()){
	 		int current = q.front();
	 		q.pop();

	 		if(current == -1){
	 			if(!q.empty()) q.push(-1);
	 			cout<<endl;
	 			continue;
	 		}

	 		cout<<current<<" dist: "<<dist[current]<<", ";
	 		// cout<<current <<"--"<<parent[current];
	 		
	 		for(auto place : this->l[current]){
	 			if(visited.find(place)==visited.end()){
	 				q.push(place);
	 				visited.insert(place);
	 				parent[place] = current;
	 				dist[place] = dist[current]+1;
	 			}
	 		}
	 		
	 		// d++;

	 	}
	 	if(dest != -1){
	 			int temp = dest;
	 			// cout<<"temp: "<<temp;
	 			// for(int i : parent) cout<<i;
	 			while(temp!=source){
	 				cout<<temp<<" -- ";
	 				temp = parent[temp];
	 			}
	 			cout<<source<<endl;
	 		}
	 	return dist[dest];
	 }
};

int min_dice_throws(int n,vector<pair<int,int> > snakes, vector<pair<int,int> > ladders){
    Graph g(n+1);
    
    for(auto p : snakes){
    	g.addEdge(p.first,p.second, false);
    }
    for(auto p : ladders){
    	g.addEdge(p.first,p.second, false);
    	cout<<"ladder: "<<p.first<<' '<<p.second<<endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i+j>n) break;
            g.addEdge(i,i+j,false);
        }
    }
    
    int res=g.bfs(1,n) -1;

    
    return res;
}
