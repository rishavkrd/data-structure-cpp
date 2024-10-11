#include <iostream>
#include <vector>
#include<map>
#include<unordered_set>

using namespace std;

#define M 3 
#define N 4 

bool visited[M][N] {false};
unordered_set<string> res;

class Node{
public:
	char c;
	bool eol;
	map<char, Node*> m;
	string word;
	Node(){
		this->eol = false;
		this->word = "";
	}

	Node(char inp){
		this->c = inp;
		this->eol = false;
		this->word = "";
	}
};

class Trie{
public:
	Node* root;
	
	Trie(){
		root = new Node();
	}
	void addWord(string s){
		Node* current = this->root;
		for(char c : s){
			
			if(current->m.find(c)==current->m.end()){
				Node* temp = new Node(c);
				current->m[c] = temp;
				current = temp;
			}
			else {
				current = current->m[c];
			}
			
		}
		current->eol = true;
		current->word = s;
		
	}
	void printTrie(Node* root){
		if(root==NULL) return ;
		if(root->eol) cout<<root->word<<endl;
		for(auto x : root->m){
			// string s="";
			Node* node = x.second;
			printTrie(node);
		}
		return;
	}


};

void board_game(char words[M][N], Node* root, int m, int n){

	if(m<0 || n<0 ||m==M || n==N || visited[m][n]){
		return;
	}
	// cout<<pattern<<",";
	visited[m][n] = true;

	int key;
	char c;

	if(root->eol){
		res.insert(root->word);
		// cout<<pattern<<endl;
	}

	int dx[] = {0, 0,1,1,1 ,-1,-1,-1};
	int dy[] = {1,-1,0,1,-1, 1, 0,-1};

	for(int i=0;i<8;i++){
		char inp = words[m+dx[i]][n+dy[i]];
		if(root->m.find(inp)!=root->m.end()){
			// cout<<"working";
			board_game(words, root->m[inp], m+dx[i], n+dy[i]);
		}
	}

	visited[m][n] = false;
	
}


int main(){

	string words[] = {"SNAKE", "FOR", "QUEZ", "SNACK", "SNACKS", "GO","TUNES","CAT"};
    
    char board[M][N] = { { 'S', 'E', 'R' ,'T'}, 
                          { 'U', 'N', 'K' ,'S'},
                          { 'T', 'C', 'A' ,'T'} };

    Trie* trie = new Trie();

    for(string s : words){
    	trie->addWord(s);
    }

    for(int i=0;i<M;i++){
    	for(int j=0;j<N;j++){
    		
    		string inp;
    		inp +=(board[i][j]);
    		// cout<<inp<<',';
    		board_game(board, trie->root,i,j);
    		inp="";
    	}
    	
    }
    // trie->printTrie(trie->root);
    for(string ans : res){
    	cout<<ans<<endl;
    }

    return 0;

}