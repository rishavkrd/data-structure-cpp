#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int index_input = 0;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }

};

void printTree(Node* root){
    //Inorder
    if(root == NULL){
        return;
    }
    cout<<root->val<<endl;
    printTree(root->left);
    
    printTree(root->right);
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        if(current == NULL){
            if(!q.empty()){
                q.push(NULL);
                cout<<endl;
            } 
            continue;
        }
        cout<<current->val<<" ";
        if(current->left !=NULL){
            q.push(current->left);
            // cout<<"left: "<<current->left->val;
        }
        if(current->right !=NULL){
            q.push(current->right);
            // cout<<"right: "<<current->right->val;
        }

    }
}


Node* buildTree(){
    // vector<int> inp = {1,2,4,-1,-1,5,7,-1,-1,-1,3,-1,6,-1,-1};
    // vector<int> inp = {1,2,4,-1,-1,5,7,-1,-1,8,9,-1,-1,10,-1,-1,3,-1,6,-1,-1};
    vector<int> bstTree = {5,3,1,-1,-1,4,-1,-1,6,-1,9,7,-1,-1,13,-1,-1};
    int d = bstTree[index_input++];
    // cin >> d;
    if(d == -1){
        return NULL;
    }
    Node* root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root;

}

bool exists(Node* root, int val){
    if(root == NULL){
        return false;
    }
    if(root->val == val) return true;
    if(root->val>val){
        return exists(root->left, val);
    } else{
        return exists(root->right, val);
    }
}

Node* minHeightBST(vector<int> arr, int s, int e){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;

    Node* root = new Node(arr[mid]);
    root->left = minHeightBST(arr, s, mid-1);
    root->right = minHeightBST(arr, mid+1, e);
    return root;
}
int closestVal=INT_MAX;
void closestInBST(Node* root, int target){
    if(root == NULL){
        return;
    }
    int current_diff = abs(root->val - target);
    if(current_diff<abs(closestVal - target)){
        closestVal = root->val;
    }
    if(root->val>target){
        closestInBST(root->left, target);

    } else{
        closestInBST(root->right, target);
    }
}

pair<Node*, Node*> flattenBST(Node* root){
    if(root == NULL){
        return {NULL,NULL};
    }
    pair<Node*, Node*> np = flattenBST(root->left);
    Node* head = np.first;
    Node* tail = np.second;

    //Handle left = NULL
    if(head == NULL){
        head = new Node(root->val);
        tail = head;
    } else{
        tail->right = new Node(root->val);
        tail = tail->right;
    }
    pair<Node*, Node*> rp = flattenBST(root->right);
    Node* rhead = rp.first;
    Node* rtail = rp.second;
    //Handle right = NULL
    if(rhead != NULL){
        tail->right = rhead;
        tail = rtail;
    }
    
    return {head, tail};
}

int inorderSuccessor(Node* root, int target){
    //leetcode
}

int main(){

    Node* root = buildTree();

    // cout<<"level Order: "<<endl;
    // levelOrderTraversal(root);

    // int val;
    // cin >> val;
    // cout<<endl<<"Exists: "<<exists(root, val)<<endl;

    vector<int> sortedArray = {1,2,3,4,5,6,7,8,9,10,11,15,20,80,90,100};
    Node* root2 = minHeightBST(sortedArray, 0, sortedArray.size()-1);
    levelOrderTraversal(root2);

    Node* root3 = flattenBST(root2).first;
    cout<<"Flatened BST: "<<endl;
    printTree(root3);

    // for(int i=0; i<15; i++){
    //     closestInBST(root, i);
    //     cout<<"closest to "<<i<<" is: "<<closestVal<<endl;
    // }
    

    return 0;
}