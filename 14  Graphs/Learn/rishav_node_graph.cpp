#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include <queue>

using namespace std;


class Node{
public:
	string name;
	vector<string> neigh;

	Node(string s){
		this->name = s;
		
	}
};
class Graph{
	unordered_map<string, Node*> m;

public:
	Graph(vector<string> s){
		for(auto x : s){
			m[x] = new Node(x);
		}
	}
	void addEdge(string a, string b, bool undir = true){
		m[a]->neigh.push_back(b);
		if(undir) {
			m[b]->neigh.push_back(a);
		}
	}
	void printNodeGraph(){
		for(auto cities : this->m){
			cout<<cities.first<<": ";
			for(auto neighbour : cities.second->neigh){
				cout<<neighbour<<"->";
			}
			cout<<endl;
		}
	}
	 void bfs(string city){
	 	unordered_set<string> visited;
	 	queue<Node*> q;
	 	q.push(this->m[city]);
	 	q.push(NULL);
	 	visited.insert(city);
	 	while(!q.empty()){
	 		Node* current = q.front();
	 		q.pop();

	 		if(current == NULL){
	 			if(!q.empty()) q.push(NULL);
	 			cout<<endl;
	 			continue;
	 		}

	 		cout<<current->name<<',';
	 		for(auto place : current->neigh){
	 			if(visited.find(place)==visited.end()){
	 				q.push(m[place]);
	 				visited.insert(place);
	 			}
	 		}

	 	}
	 }


};



int main(){

	vector<string> v;
	v.push_back("Delhi");
	v.push_back("New York");
	v.push_back("Denver");
	v.push_back("Houston");
	
	Graph g(v);

	g.addEdge("Delhi", "New York");
	g.addEdge("Delhi", "Houston");
	g.addEdge("Houston", "New York");
	g.addEdge("Houston", "Denver");

	// g.printNodeGraph();

	g.bfs("Delhi");

	return 0;
}