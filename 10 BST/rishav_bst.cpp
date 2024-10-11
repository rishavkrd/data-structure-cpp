#include<iostream>
#include<vector>
#include<queue>

using namespace std;


class Node{
public:
	int val;
	Node* left;
	Node* right;
	Node(){
		val = 0;
		left = NULL;
		right = NULL;
	}
	Node(int x){
		val = x;
		left = NULL;
		right = NULL;
	}
};

Node* insertBST(Node* root, int x){
	Node* temp = new Node(x);
	if(root==NULL){
		return temp;
	}
	
	if(x<root->val){
		root->left = insertBST(root->left, x);
	} else{
		root->right = insertBST(root->right, x);
	}
	return root;
}
void levelOrderPrint(Node* root){
	queue<Node*> q;
	if(root==NULL) return;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		Node* current = q.front();
		q.pop();
		if(current == NULL){
			// q.pop();
			if(!q.empty()) q.push(NULL);
			cout<<endl;
			continue;

		}
		cout<<current->val<<" ";
		if(current->left!=NULL){
			q.push(current->left);
		}
		if(current->right!=NULL){
			q.push(current->right);
		}
	}
}

void printInOrder(Node* root){
	if(root == NULL) return ;
	printInOrder(root->left);
	cout<< root->val<< " ";
	printInOrder(root->right);
	return;
}

bool isPresent(Node * root,int key){
    if(root == NULL) return false;
    if(key == root->val) return true;
    if( key<root->val ) return isPresent(root->left, key);
    else return isPresent(root->right, key);

    return false;
    
}

//Q. Min height BST

Node* minHeightBST(int* x, int s, int e){
	if(s>e){
		return NULL;
	}
	// Node* temp = new Node(x);
	// if(s==e) return temp;

	int mid = (s+e)/2;

	Node* root = new Node(x[mid]);
	root->left = minHeightBST( x, s, mid-1);
	root->right = minHeightBST( x, mid + 1, e);

	return root;
}

//Q. Closet BST

//find the bug in this code.
int bug_closest(Node* root, int target){
	if(root==NULL) return -1;
	int res = root->val;
	int diff = abs(res - target);

	while(root!=NULL){
		if(root->left!=NULL && abs(root->left->val - target) < diff){
			
			root = root->left;
			res = root->val;
			diff = abs(res - target);
														//Bug: search for 4;
		}
		else if(root->right!=NULL && abs(root->right->val - target) < diff){
			
			root = root->right;
			res = root->val;
			diff = abs(res - target);
		}
		else break;
		
	}
	return res;
}

int closest(Node* root, int target){
	if(root == NULL ) return -1;
	int diff = abs(root->val - target);
	int res = root->val;

	while(root!=NULL){
		if(root->val == target) return root->val;
		int current_diff = abs(root->val - target);

		if(current_diff<diff){
			res = root->val;
			diff = current_diff;
		}
		if(target < root->val){
			root = root->left;
		} else{
			root = root->right;
		}
	}
	return res;
}

//Q. Flatten Tree
class HTpair{
public:
	Node* head;
	Node* tail;
	HTpair(){
		head = NULL;
		tail = NULL;
	}
};

HTpair flattenTree(Node* root){
	HTpair res;
	if(root == NULL) return res;

	HTpair l, r;

	l = flattenTree(root->left);
	if(l.head != NULL){
		l.tail->right = root;
		root->left = NULL;
		res.head = l.head;
	} else{
		res.head = root;
	}

	r = flattenTree(root->right);
	if(r.head!=NULL){
		root->right = r.head;
		res.tail = r.tail;
	} else{
		res.tail = root;
	}
	
	return res;
}

//Q. Indorder Successor
int successor(Node* root, int target, bool found){
	if(root == NULL) return -1;

	

	if(target == root->val) {
		if(found) return root->val;
		found = true;
		target++;
		if(root->right!=NULL) return successor(root->right, target, found);
		return -2;
	}
	int res=-1;
	if(target<root->val) res = successor(root->left,target, found);
	if(res == -2) return root->val;
	if(res!=-1) return res;
	if(found){
		return root->val;
	}
	if(target>root->val) res = successor(root->right, target, found);
	if(res==-2) return -2;

	return res;
}

int main(){
	Node* root = NULL;
	int arr[] = {8,3,10,1,6,14,4,7,13,11};
	for(int i : arr){
		root = insertBST(root, i);
	}

	// int arr2[] = {1,2,3,4,5,6,7};
	// root = minHeightBST(arr2, 0,6);
	
	
	// cout<<endl;

	// cout<<"closest: "<< closest(root,x)<<endl;

	// HTpair flatTree = flattenTree(root);

	// root = flatTree.head;

	int x;
	cin>>x;
	cout<<"Successor of "<< x << " is : "<<successor(root, x, false)<<endl;

	levelOrderPrint(root);
	// printInOrder(root);

	return 0;
}