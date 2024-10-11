#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;

	Node(int d){
		this->data = d;
		this->left = NULL;
		this->right = NULL;
	}
};

Node* buildTree(){
	int d;
	cin>>d;

	if(d == -1){
		return NULL;
	}

	Node* n = new Node(d);
	n->left = buildTree();
	n->right = buildTree();

	return n;
}

void printTree(Node * root){
	if(root == NULL) {
		cout<<-1<< ' ';
		return;
	}
	cout<<root->data<<' ';
	printTree(root->left);
	printTree(root->right);
	return;

}

//Q. Do the level order print of a tree

void levelOrderPrint(Node* root){
	if(root==NULL) {
		cout<<"NULL"<<endl;
		return;
	}
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		if(q.front()==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()) q.push(NULL);
			
			
		} else {

			Node* n = q.front();
			cout<<n->data<<' ';
			if(n->left!=NULL) q.push(n->left);
			if(n->right!=NULL) q.push(n->right);
			q.pop();
		}
	}
	return;

}

//Q. Build a tree from a level order input

Node* levelOrderBuild(){
	queue<Node*> q;
	// int num = 1;
	// q.push()
	int n;
	cin>>n;
	Node* root = new Node(n);
	q.push(root);
	// bool left=true;

	//Prateek sir's implementation
	while(!q.empty()){
		int c1, c2;
		Node* current = q.front(), *temp;
		q.pop();
		cin>>c1>>c2;
		if(c1!=-1){
			temp = new Node(c1);
			current->left = temp;
			q.push(temp);
		}
		if(c2!=-1){
			temp = new Node(c2);
			q.push(temp);
			current->right = temp;
		}
	}

	//******** Rishav's Implementation **********
	// while(!q.empty()){
	// 	cin>>n;
	// 	Node* node = NULL, *parent = q.front();
		
	// 	if(n!=-1) {
	// 		node = new Node(n);
	// 		q.push(node);
	// 	}
	// 	if(left) parent->left = node;
	// 	else {
	// 		parent->right = node;
	// 		q.pop();
	// 	}
	// 	left=!left;

	// }
	return root;
}
//***-----------------------*******-------------------

//Q. Calculate the diameter of a tree

int height(Node* root){
	if(root == NULL){
		return 0;
	}
	return max(height(root->left)+1, height(root->right)+1);
}
vector<int> my_diameter(Node* root){
	vector<int> dia_h(2,0);
	if(root==NULL) return dia_h;
	// int current = height(root->left) + height(root->right);
	vector<int> left = my_diameter(root->left);
	vector<int> right = my_diameter(root->right);

	
	int current_dia = left[1] + right[1];	//height left + height right
	int current_height = max(left[1],right[1])+1;

	dia_h[0] =  max(current_dia, max(left[0],right[0])); 	//max diameter
	dia_h[1] = current_height; 				//height

	return dia_h;
}
class HDpair{
public:
	int height;
	int diameter;

	HDpair(){
		height = 0;
		diameter = 0;
	}
};

HDpair diameter(Node* root){
	HDpair res;					// = new HDpair();
	if(root == NULL) return res;

	HDpair left = diameter(root->left);
	HDpair right = diameter(root->right);

	res.height = max(left.height, right.height) + 1;
	int current_dia = left.height + right.height;
	res.diameter = max(current_dia, max(left.diameter, right.diameter));
	return res;
}

//Q. Replace with Sum

int repacewithsum(Node* root){
	if(root == NULL) return 0;
	int root_val = root->data;
	int psum = repacewithsum(root->left) + repacewithsum(root->right);
	if(root->left!=NULL && root->right!=NULL) root->data = psum;
	
	return psum+root_val;
}

//Q. Balanced Tree?

pair<int, bool> balancedTree(Node* root){
	pair<int, bool> res;
	res.second=true;
	if(root == NULL) return res;
	pair<int,bool> left = balancedTree(root->left);
	pair<int,bool> right = balancedTree(root->right);
	

	if(abs(left.first-right.first)>1 or left.second==false or right.second==false) res.second=false;
	
	res.first = max(left.first,right.first)+1;
	return res;
}

//Q. Max subset sum

int mymaxSubsetSum(Node * root){
	if(root==NULL) return 0;
	int not_incl = mymaxSubsetSum(root->left) + mymaxSubsetSum(root->right);
	int incl = root->data;
	if(root->left!= NULL) incl+=mymaxSubsetSum(root->left->left)+mymaxSubsetSum(root->left->right);		
	//## Did a mistake here by adding the root value inside the if statement 
	//which meant, a leaf node's value will not be included
	if(root->right!=NULL) incl+=mymaxSubsetSum(root->right->left)+mymaxSubsetSum(root->right->right);

	return max(not_incl, incl);
}

class Pair{
public:
	int inc;
	int exc;
	Pair(){
		inc = 0;
		exc = 0;
	}
};
Pair maxSubsetSum(Node* root){
	Pair res;
	if(root == NULL) return res;
	Pair left = maxSubsetSum(root->left);
	Pair right = maxSubsetSum(root->right);
	res.inc = root->data + left.exc + right.exc;
	res.exc = max(left.exc, left.inc) + max(right.inc, right.exc);

	return res;
}

//Print at level K
void printAtLevelK(Node* root, int k){
	if(root==NULL){
		return;
	}
	if(k==0){
		cout<< root->data<<' ';
	}
	printAtLevelK(root->left, k-1);
	printAtLevelK(root->right, k-1);
	return;

}

class KDpair{
public:
	bool found;
	int n;
	KDpair(){
		found = false;
		n = 0;
	}
};

KDpair kdistance(Node* root, int target, int k){
	KDpair res;
	if(root == NULL) return res;
	if(root->data == target){
		res.found = true;
		res.n = 1;
		printAtLevelK(root, k);
		return res;
	}
	KDpair left = kdistance(root->left, target, k);
	KDpair right = kdistance(root->right, target, k);

	if(left.found == true || right.found==true){
		int dist = left.found==true? left.n : right.n;
		if(k-dist == 0) cout<<(root->data);
		else{
			if(left.found){
				printAtLevelK(root->right, k-dist-1);
			} else{
				printAtLevelK(root->left, k-dist-1);
			}
		}
		
		res.found = true;
		res.n =dist+1;
	}
	return res;
}

//Q. Vertical Print
map<int, vector<int>> vtree;
void verticalOrderPrint(Node* root, int l){
	if(root == NULL) return;

	// if(vtree[l]==vtree.end()){
	// 	vector<int> v;
	// 	v.push_back(root->data);
	// 	vtree.pair_insert(l, v);
	// } else{
		vtree[l].push_back(root->data);
	// }
	verticalOrderPrint(root->left, l-1);
	verticalOrderPrint(root->right, l+1);
}

int main(){
	Node* node;
	// node = buildTree();
	node = levelOrderBuild();

	// repacewithsum(node);
	
	// if(balancedTree(node).second) cout<<"Balanced Tree"<<endl;
	// else cout<<"Not Balanced Tree"<<endl;

	// Pair res = maxSubsetSum(node);
	// cout<<max(res.inc, res.exc)<<endl;

	// levelOrderPrint(node);

	Node* root = new Node(1);
	root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);

	verticalOrderPrint(root, 0);
	// iterator i = vtree.begin();
	for(auto i : vtree){
		for(int x : i.second){
			cout<<x<<" ";
		}
		cout<<endl;
		// i++;
	}

	// printAtLevelK(node,2);

	// cout<<"kdistance nodes: "<<endl;
	// kdistance(node, 5, 2);

	// cout<< diameter(node).diameter<<endl;
	return 0;
	// printTree(node);

}