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

Node* buildFromLevelOrder(vector<int> nums){
    Node* root = new Node(nums[0]);
    queue<Node*> q;
    q.push(root);

    for(int i=0; i<nums.size()-2; i+=2){
        Node* current = q.front();
        q.pop();

        if(current==NULL) continue;

        if(nums[i+1]!=-1) current->left = new Node(nums[i+1]);
        if(nums[i+2]!=-1) current->right = new Node(nums[i+2]);

        q.push(current->left);
        q.push(current->right);
    }
    return root;
}

Node* buildTree(){
    // vector<int> inp = {1,2,4,-1,-1,5,7,-1,-1,-1,3,-1,6,-1,-1};
    vector<int> inp = {1,2,4,-1,-1,5,7,-1,-1,8,9,-1,-1,10,-1,-1,3,-1,6,-1,-1};
    int d = inp[index_input++];
    // cin >> d;
    if(d == -1){
        return NULL;
    }
    Node* root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root;

}
int max_dia=0;
int getHeight(Node* root){
    if(root==NULL){
        return 0;
    }
    int lheight = getHeight(root->left);
    int rheight = getHeight(root->right);

    cout<<root->val<<" :heights: "<<lheight<<","<<rheight<<endl;

    max_dia = max(lheight+rheight, max_dia);

    return 1+max(lheight, rheight);
}

int sumDecendents(Node* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return root->val;
    }
    int leftsum = 0, rightsum =0, rootval = root->val;

    leftsum = sumDecendents(root->left);
    rightsum = sumDecendents(root->right);

    root->val = leftsum+rightsum;

    return rootval + root->val;
}
bool balanced=true;
int balancedTree(Node* root){
    if(root == NULL){
        return 0;
    }
    int lefth = balancedTree(root->left);
    int righth = balancedTree(root->right);

    if(abs(lefth-righth)>1){
        balanced = false;
    }
    return max(lefth,righth)+1;
}

int maxSubsetSum(Node* root, bool skip){
    if(root == NULL){
        return 0;
    }
    if(skip){
        return maxSubsetSum(root->left, false) + maxSubsetSum(root->right, false);
    }
    int include = root->val + maxSubsetSum(root->left, true) + maxSubsetSum(root->right, true);
    int exclude = maxSubsetSum(root->left, false) + maxSubsetSum(root->right, false);
    return max(include, exclude);
}
int findNode(Node* root, Node* node){
    if(root == NULL){
        return -1;
    }
    if(root == node){
        return 0;
    }
    int leftdist = findNode(root->left, node);
    int rightdist = findNode(root->right, node);

    if(leftdist != -1){
        return 1+leftdist;
    } else if(rightdist!=-1){
        return 1+rightdist;
    }
    return -1;
}

void bottomKnodes(Node* node, int k, vector<Node*> &vec, Node* ref){
    if(node == NULL || node==ref){
        return;
    }
    if(k==0){
        vec.push_back(node);
    }
    bottomKnodes(node->left, k-1, vec, ref);
    bottomKnodes(node->right, k-1, vec, ref);
}

void topKnodes(Node* root, Node* node, int k, vector<Node*> &vec){
    if(root == NULL) return;
    int distance = findNode(root, node);
    // cout<<"Distance to node: "<<distance<<endl;
    int remDist = k - distance;
    if(remDist<0) return;
    bottomKnodes(root, remDist, vec, node);

    topKnodes(root->left, node, k, vec);
    topKnodes(root->right, node, k, vec);

}

void nodesAtk(Node* root, Node* node, int k){
    vector<Node*> bottomK, topK;
    bottomKnodes(node, k, bottomK, NULL);
    topKnodes(root, node, k, topK);

    for(auto n : bottomK){
        cout<<endl<<n->val;
    }
    for(auto n : topK){
        cout<<endl<<n->val;
    }
    return;

}

int main(){
    vector<int> levelOrderNodes = {1,2,3,4,5,-1,6,-1,-1,7,-1,-1,-1,-1,-1};

    Node* root = buildTree();
    printTree(root);

    cout<<"level Order: "<<endl;
    levelOrderTraversal(root);

    cout<<endl<<"build from level order"<<endl;
    Node* root2 =buildFromLevelOrder(levelOrderNodes);
    levelOrderTraversal(root2);

    getHeight(root);
    cout<<endl<<"Max Diameter: "<<max_dia;

    cout<<endl<<"Sum Decendents"<<endl;
    sumDecendents(root2);
    levelOrderTraversal(root2);

    balancedTree(root);
    cout<<endl<<"Balanced Tree: "<<balanced<<endl;

    cout<<"Max Subset Sum: "<<maxSubsetSum(root,false)<<endl;

    cout<<"Node at distance K: "<<endl;
    nodesAtk(root, root->left->right, 2);



    return 0;
}