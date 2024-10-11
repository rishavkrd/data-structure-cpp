//rishav's graph
#include<iostream>
#include<list>
#include<unordered_set>
#include<queue>
#include<climits>
#include<set>
using namespace std;

class Graph{
	int V;
	list<pair<int,int>> *l;
public:
	Graph(int v){
		V = v;
		l = new list<pair<int,int>>[v];
	}

	void addEdge(int a, int b, int w, bool undir = true){
		l[a].push_back({w,b});
		if(undir){
			l[b].push_back({w,a});
		}
	}
	void printAdjList(){

		for(int i=0;i<this->V;i++){
			cout<<i<<" : ";
			for(auto j : l[i]){
				cout<<j.second<<"-->";
			}
			cout<<endl;
		}
		
	}


	 int dijkstra(int source, int dest){
		set<pair<int, int>> set;
		int dist[this->V];

		for(int i=0;i<this->V;i++){
			dist[i] = INT_MAX;
		}
		dist[source] = 0;
		set.insert({0,source});	//dist, node
		bool visited[this->V] = {false};

		// while(!set.empty()){
		// 	for(int node : this->l[source]){

		// 	}
		// }
		int current_dist = 0;
		while(!set.empty()){
			auto p = *set.begin();
			int node = p.second;
			current_dist = p.first;
			// visited[node] = true;
			for(auto x : this->l[node]){
				// if(visited[x]) continue;
				int w = x.first;
				int v = x.second;
				if(w + current_dist < dist[v]){
					if(set.find(x)!= set.end()) set.erase(x);
					
					dist[v]= w + current_dist;
					set.insert({dist[v],v});

				}
			}
			set.erase(p);
		}
		for(int i=0; i<this->V;i++){
			cout<<"Distance of "<<i<< " is: "<<dist[i]<<endl;
		}
		return dist[dest];

	}
};


int main(){
	Graph g (5);
	g.addEdge(0,1,1);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(1,2,1);
	g.addEdge(2,3,2);
	g.addEdge(4,3,3);
	// g.addEdge(5,4);
	
	// g.printAdjList();
	// g.bfs(5,1);

	// g.dfs(1);
	g.dijkstra(0,4);


	return 0;
}