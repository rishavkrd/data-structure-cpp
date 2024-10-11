//rishav's graph
#include<iostream>
#include<list>
#include<unordered_set>
#include<queue>
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
	void bfs(int source, int dest=-1){
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

	 		cout<<current<<" dist: "<<dist[current]<<',';
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
	 }
	 void dfs(int source){
	 	bool visited[this->V] = {false};

	 	helper_dfs(source, visited);
	 }
	 void helper_dfs(int source, bool *visited){
	 	if(visited[source]) return;
	 	visited[source] = true;
	 	cout<<source<<",";
	 	for(int x : this->l[source]){
	 		helper_dfs(x, visited);
	 	}

	 }

	 
};

int min_dice_throws(int n,vector<pair<int,int> > snakes, vector<pair<int,int> > ladders){
    Graph g(n+1);
    //add for 1->6 dice
    for(auto p : snakes){
    	g.addEdge(p.first,p.second, false);
    }
    for(auto p : ladders){
    	g.addEdge(p.first,p.second, false);
    }

    
    g.bfs(1,n);
    return 0;
    
}

int main(){
	Graph g (6);
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(2,1);
	g.addEdge(2,3);
	g.addEdge(4,3);
	g.addEdge(5,3);
	g.addEdge(5,4);
	
	// g.printAdjList();
	// g.bfs(5,1);

	g.dfs(1);


	return 0;
}