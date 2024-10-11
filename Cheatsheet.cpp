#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <list>
#include <map>
#include <queue>
#include <set>

using namespace std;

class Arrays{
	virtual vector<vector<int>> triplet(vector<int> arr, int sum) = 0;
};

class Strings{
	vector<string> tokenization(string input){
        vector<string> tokenlist;
        char* token = strtok((char*) input.c_str(), ",");
        while(token!=NULL){
            token = strtok(NULL, ",");
            tokenlist.push_back(token);
        }
        return tokenlist;
    }
};
class SlidingWindow{
    // a. Structure: 
	// 		i. For all the elements
	// 			1) While (condition not satisfied) fix it
	// 			2) Approach the solution
};
		
class Sorting{
    // a. Merge Sort Structure:
	// 	b. if(s<=e)
	// 		i. Merge sort (0,mid)
	// 		ii. Merge sort (mid+1, e)
	// 	c. Merge (left half, right half)
};
class BinarySearch{
		// a. Lower_bound, Upper_bound usage
		// 	i. Structure:
		// 	ii. While(s<=e)
		// 		1) Pivot = (s+e)/2
		// 		2) Equal
		// 			a) Return/lower/upper
		// 		3) Pivot < target
        //             b) s = pivot + 1;
		// 		4) Pivot > target
        //             c) e = pivot - 1;

};

class Recursion{
    vector<string> subsets(string input){
        //Input: abc. Output: ["",a,b,c,ab,ac,bc,abc]
        // Output includes/excludes first letter, Input is substr(1)
        return vector<string>();
    }
    vector<string> permutaions(string input){
        //Input: abc. Output: [abc,acb,bac,bca,cab,cba]
        //Swap ith letter with all the letters after it. Recursively permute i+1th string
        //Note on backtracking: After swapping, swap back to original. (is not clear to me)
    }

};
class Node{
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        next = NULL;
    }
};
class LinkedList{
    virtual Node* reverse(Node* head) = 0;
    virtual Node* kreverse(Node* head, int k) = 0;
    //Runner Technique (fast and slow pointers)
        //a. Detecting a cycle
        //b. Finding the middle element
        //c. Finding the kth element from the end
        //d. Finding the intersection point of two linked lists
        //e. Detecting the palindrome?
};

class StacksQueues{
    virtual vector<int> maxSubarray(vector<int> input, int k) = 0;
        //Input: [1,3,-1,-3,5,3,6,7], k = 3. Output: [3,3,5,5,6,7]
};

class BinaryTrees{
    virtual void buildTree() = 0;
    virtual void printLevelOrder(Node* root) = 0;
    virtual void levelOrderBuildTree(Node* root) = 0;
    virtual int height(Node* root) = 0;
    virtual int diameter(Node* root) = 0;
    virtual bool isBalanced(Node* root) = 0;
    virtual bool isBST(Node* root) = 0;
    virtual int maxPathSum(Node* root) = 0;
    virtual void nodeAtK(Node* root, int k) = 0;
};

class BST{
    virtual Node* minHeightBST(vector<int> input) = 0;
    virtual void flatten(Node* root) = 0;
};

class PriorityQueue{
    virtual void initializePriorityQueue() = 0; //Min, Max heap
    virtual void findKNearestCabs() = 0;
    virtual void runningMedian() = 0;
    virtual void kWayMerge() = 0;

};

class Graph{
    virtual void buildGraph(int n) = 0;
//Given a Edge list
    //Option 1: Simple Graph with (1) int V; 
                        // (2) list<int> *l; which points to an array of list<int>[V];
                //Constructor to initialize V edges, AddEdge function.
    //Option 2:
        //Using Node, building graph is not so straight forward.
        //You need (1) GraphNode : int val, list<GraphNode*> neigh.
                // (2) Graph : map<int, GraphNode*>, int verticesCount, (optional) bool directed
                            // Constructor to initialize all verticesCount nodes.
                            // addEdge(int a, int b) function
    virtual void bfs() = 0;
    virtual void dfs() = 0;
        // Unlike trees graphs needs to maintain visited array because parent, 
        // back pointers to same node.
    virtual void topologicalSort() = 0;
    virtual void dijkstra() = 0;
    virtual void cycleInUndirected() = 0;   
        // Cycle exists if except parent if a node repeats.
        //needs a visited array and a parent pointer.
    virtual void cycleInDirected() = 0;
        //Cycle exists if durring the exploration of a node, it is visited again.
        //Needs a visited and a dp array.
    virtual void shortestGridPath() = 0; 
        //Dijkstra's algorithm
    virtual void largestIsland() = 0;
        //2D DFS with sinking islands and choosing sum of all valid explored islands.
    virtual void largestSubsequence() = 0;
        //2D DFS with choosing max of all valid explored paths.
    
};

class DynamicProgramming{
    virtual void fibonacci() = 0;
    virtual void coinChange() = 0;
    virtual void longestIncreasingSubsequence() = 0;
    virtual void longestCommonSubsequence() = 0;
    virtual void longestCommonSubstring() = 0;
    virtual void editDistance() = 0;
    virtual void knapsack() = 0;
    virtual void subsetSum() = 0;
    virtual void rodCutting() = 0;
    virtual void matrixChainMultiplication() = 0;
    virtual void wordBreak() = 0;
    virtual void minCostPath() = 0;
    virtual void minJumps() = 0;
    virtual void minPalindromicCuts() = 0;
    virtual void minPalindromicPartitions() = 0;
    virtual void minPalindromicSubsequence() = 0;
    virtual void maxPalindromicSubsequence() = 0;
    virtual void maxPalindromicSubstring() = 0;
    virtual void longestPalindromicSubstring() = 0;
};

    class GraphNode{
    public:
        int val;
        list<GraphNode*> neigh;

        GraphNode(int val){
            this->val = val;
        }

    };

    class SimpleGraph{      //0-indexed
    public:
        int V;
        list<int>* l;
        bool directed;

        SimpleGraph (int n, bool isDirected = false){
            directed = isDirected;
            V = n;
            l = new list<int>[n];
        }
        void addEdge(int a, int b){
            l[a].push_back(b);
            if(!directed){
                l[b].push_back(a);
            }
        }
        void buildGraph(){
            if(V<6){
                cout<<"Please create graph >= 6 nodes"<<endl;
                return;
            }
            addEdge(0,1);
            addEdge(1,2);
            addEdge(2,3);
            addEdge(0,4);
            addEdge(0,5);
            addEdge(4,5);    //Cycle in undirected
            // addEdge(3,0);   //Cycle in directed
        }

        void dfs_helper(int idx, vector<bool> &visited){
            if(visited[idx]){
                return;
            }
            visited[idx] = true;
            cout<<idx<<endl;
            for(int node : l[idx]){
                dfs_helper(node, visited);
            }
        }

        void dfs(int s){
            vector<bool> visited(V,0);
            dfs_helper(s, visited);

        }

        void bfs(int s){
            queue<int> q;
            q.push(s);
            q.push(-1);
            int level = 0;
            vector<bool> visited(V, 0);
            while(!q.empty()){
                int current = q.front();
                q.pop();
                if(current == -1){
                    if(!q.empty()){
                        q.push(-1);
                    }
                    level++;
                    continue;
                }
                if(visited[current]) continue;
                visited[current] = true;
                cout<<current<<" : "<<level<<endl;
                for(int node : l[current]){
                    cout<<"Node: "<<node<< " ";
                    q.push(node);
                }
                cout<<endl;
            }

        }
        bool undirectedCycleDfs(vector<bool> &visited, int current, int parent){
            //base case : No for loops
            visited[current] = true;
            cout<<"visited: "<<current<<endl;
            bool hasCycle = false;
            for(int node : l[current]){
                if(node!=parent){
                    if(visited[node] == true){
                        cout<<"Cycle at: "<<node<<", "<<current<<endl;
                        return true;
                    }
                    hasCycle = hasCycle | undirectedCycleDfs(visited, node, current);
                }
            }
            return hasCycle;
        }
        void undirectedCycle(){
            vector<bool> visited(V, 0);

            for(int i=0; i<V; i++){
                if(!visited[i]){
                    if(undirectedCycleDfs(visited, i, 0)){
                        cout<<"Found Cycle"<<endl;
                        return;
                    }
                }
            }
            return;
        }

        bool directedCycleDfs(vector<bool> &visited, vector<bool> &cycleExists, int current){
            
            visited[current] = true;
            bool res = false;

            cout<<"visited: "<<current<<endl;
            for(int node : l[current]){
                if(visited[node] == true){
                    if (cycleExists[node]){
                        cout<<"cycle found: "<<node <<", "<<current<<endl;
                    }
                    return cycleExists[node];
                }
                res = res | directedCycleDfs(visited, cycleExists, node);
            }
            return cycleExists[current] = res;
        }

        void directedCycle(){
            vector<bool> visited(V,0);
            vector<bool> cycleExists(V,1);

            for(int i=0; i<V;i++){
                if(!visited[i]){
                    directedCycleDfs(visited, cycleExists, i);
                }
            }
        }
    };

class WeightedGraph{
public:
    int V;
    list<pair<int,int>> *l;


    WeightedGraph(int n){
        V = n;
        l = new list<pair<int,int>>[V];
    }
    void addEdge(int a, int b, int w){
        l[a].push_back({b,w});
        l[b].push_back({a,w});
    }
    void buildGraph(){
        if(V<6){
            cout<<"Error: V<6"<<endl;
            return;
        }
        addEdge(0,1,1);
        addEdge(0,3,7);
        addEdge(0,2,4);
        addEdge(1,2,1);
        addEdge(2,3,2);
        addEdge(3,4,3);
        addEdge(4,5,1);
    }
    void dijkshtra(int start){
        set<pair<int,int>> s;
        s.insert({0,start});
        vector<int> distances(V,INT_MAX);
        distances[start] = 0;

        while(!s.empty()){
            auto dn = s.begin();
            int currentDist = dn->first;
            int currentNode = dn->second;
            s.erase(dn);
            cout<<"Current: "<<currentNode<< " dist: "<<currentDist<<endl;
            for(pair<int,int> np : l[currentNode]){
                int node = np.first;
                int weight = np.second;

                int distance = currentDist + weight;

                if(distances[node]>=distance){
                    distances[node] = distance;
                    s.insert({distance, node});
                    cout<<"visiting "<<node<<" - distance: "<<distance<<endl;
                }

            }
        }
        cout<<"Shortest distances: \n";
        for(int i=0; i<V; i++){
            cout<<i<<" : "<<distances[i]<<endl;
        }
    }

};

void testSimpleGraphsDfs(){
    SimpleGraph g(6);
    g.buildGraph();
    g.dfs(0);
}

void testSimpleGraphBfs(){
    SimpleGraph g(6);
    g.buildGraph();
    g.bfs(0);
    // g.bfs(5);
}

void testSimpleUndirectedGraphCycle(){
    SimpleGraph g(6);
    g.buildGraph();
    g.undirectedCycle();

}

void testSimpleDirectedHasCycle(){
    SimpleGraph g(6, true);
    g.buildGraph();
    g.directedCycle();
}

void testDijkshta(){
    WeightedGraph g(6);
    g.buildGraph();
    g.dijkshtra(0);
}

void shortestGridPath(){
    vector<vector<int>> v = {
                            {31, 100, 65, 12,  18},
                            {10,  13,  47, 157, 6},
                            {100, 113, 174, 11, 33},
                            {88,  124, 41,  20, 140},
                            {99,  32,  111, 41, 20}
                        };
    

    int res = 0;
    set<pair<int, pair<int,int>>> s;
    s.insert({v[0][0], {0,0}});
    vector<vector<int>> distances(v.size(), vector<int>(v[0].size(), INT_MAX));

    while(!s.empty()){
        auto it = s.begin();
        pair<int,int> currentNode = it->second;
        int currentDist = it->first;
        s.erase(it);

        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};

        for(int k=0; k<4; k++){
            int x = currentNode.first + dx[k];
            int y = currentNode.second + dy[k];

            if(x<0 || y<0 || x>=v.size() || y>=v[0].size()){
                continue;
            }
            int distance = currentDist + v[x][y];
            if(distances[x][y]>= distance){
                s.insert({distance, {x,y}});
                distances[x][y] = distance;
            }
        }
    }
    res = distances[v.size()-1][v[0].size()-1];
    cout<<res<<" -- result" <<endl;
}

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v){
        val = v;
        left = NULL;
        right = NULL;
    }
};

class Trees{
    // virtual void buildTree() = 0;
    // virtual void printLevelOrder(Node* root) = 0;
    // virtual void levelOrderBuildTree(Node* root) = 0;
    // virtual int height(Node* root) = 0;
    // virtual int diameter(Node* root) = 0;
    // virtual bool isBalanced(Node* root) = 0;
    // virtual bool isBST(Node* root) = 0;
    // virtual int maxPathSum(Node* root) = 0;
    // virtual void nodeAtK(Node* root, int k) = 0;
public:

    TreeNode* buildTree(){
        TreeNode* root = new TreeNode(1);
        TreeNode* two = new TreeNode(2);
        TreeNode* three = new TreeNode(3);
        TreeNode* four = new TreeNode(4);
        TreeNode* five = new TreeNode(5);
        TreeNode* six = new TreeNode(6);

        root->left = two;
        root->right = three;
        two->left = four;
        two->right = five;
        five->left = new TreeNode(7);
        three->right = six;

        return root;
    }
    void dfs(TreeNode* root){
        if(root == NULL){
            return;
        }
        cout<<root->val<<endl;
        dfs(root->left);
        dfs(root->right);
    }
    void bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode *current = q.front();
            q.pop();

            if(current == NULL){
                if(!q.empty()){
                    q.push(NULL);
                    cout<<endl;
                }
                continue;
            }
            cout<<current->val<<", ";
            if(current->left!=NULL){
                q.push(current->left);
            }
            if(current->right!=NULL){
                q.push(current->right);
            }
        }
    }
    int height(TreeNode* root, int &dia){
        if(root==NULL){
            return 0;
        }

        int left = height(root->left, dia);
        int right = height(root->right, dia);
        
        int res = max(left, right);
        dia = max(dia, left+right);

        return res+1;

    }
    void diameter(TreeNode* root){
        int dia=0;

        height(root, dia);
        cout<<"Diameter: "<<dia<<endl;
    }

};

void testTreeDfs(){
    Trees t;
    TreeNode* root = t.buildTree();
    t.dfs(root);

}

void testTreeBfs(){
    Trees t;
    TreeNode* root = t.buildTree();
    t.bfs(root);
}

void testTreeDia(){
    Trees t;
    TreeNode* root = t.buildTree();
    t.diameter(root);
}
int mystrcmp(const char* a, const char* b){
    // char* i=a, *j=b;
    int res = 0;
    while(*a!=0 && *b!=0){
        // cout<<*a<<", "<<*b<<endl;
        if(*a < *b){
            return -1;
        } else if(*a>*b){
            return 1;
        }
        a++;
        b++;

    }
    if(*a!=0) return 1;
    if(*b!=0) return -1;
    return 0;
}
void testStrcmp(){
    string a = "abcde";
    string b = "abcdef";
    
    cout<<"My: "<<mystrcmp(a.c_str(),b.c_str())<<endl;
    cout<<"OG: "<<strcmp(a.c_str(),b.c_str())<<endl;
    
}

void missingNumber(){
    
    int ar[] = { 2, 3, 4, 5, 6, 7, 8, 9 };
    int size = sizeof(ar) / sizeof(ar[0]);
    int res = -1;

    int s=0, e=sizeof(ar)/sizeof(int)-1;

    while(s<=e){
        int pivot = (s+e)/2;
        int diff = ar[pivot] - pivot;
        if(diff==1){
            s = pivot+1;
        } else if(diff == 2){
            if(pivot==0 || ar[pivot-1]-(pivot-1) == 1){
                cout<<"Missing: "<< pivot+1<<endl;
                return;
            }
            e = pivot -1;
        }
    }
    return;
}

class SmartPointer{
public:
    int *p;
    SmartPointer(int *ptr=NULL){
        p = ptr;
        cout<<"Created object"<<endl;
    }
    ~SmartPointer(){
        cout<<"Going to delete object: "<<*p<<endl;
        delete p;
        cout<<"deleted object: "<<*p<<endl;
        p = 0;
        cout<<"set p = 0 to prevent OS from throwing error when deleting p again"<<endl;
        delete p;
        cout<<"delete p again to check if OS throws error"<<endl;
    }

    int& operator *(){
        return *p;
    }

};

void testSmartPointer(){
    
    SmartPointer sptr(new int());
    *sptr = 20;
    cout << *sptr<<endl;

}

int main(){
    // testUndirectedGraphCycle();
    // testSimpleUndirectedGraphCycle();
    // testSimpleDirectedHasCycle();
    // testSimpleGraphBfs();
    // testSimpleGraphsDfs();
    // testDijkshta();
    // shortestGridPath();
    // testTreeBfs();
    // testTreeDia();
    // testStrcmp();
    // missingNumber();
    testSmartPointer();
    return 0;
}










//--------------------------------------------------------------------//


class GraphRevision2{       //1-indexed
public:
    map<int, GraphNode*> m;
    int v;
    bool directed;
    GraphRevision2(int n, bool isDirected=false){
        directed = isDirected;
        v = n;
        for(int i=1; i<=n; i++){
            m[i] = new GraphNode(i);
        }
    }

    void buildGraph(){
        addEdge(1,2);
        addEdge(2,3);
        // addEdge(3,1);
        addEdge(1,4);
        addEdge(1,5);
        addEdge(4,5);   //Cycle
    }

    void addEdge(int a, int b){
        m[a]->neigh.push_back(m[b]);
        if(!directed){
                m[b]->neigh.push_back(m[a]);
            }
    }

    bool dfs_helper(int s, vector<bool> &visited, int parent){
        //base case: no for loop iteration
        visited[s] = true;
        cout<<"visited: "<<s<<endl;
        bool res = false;
        for(GraphNode* node : m[s]->neigh){
            if(node->val == parent) {
                continue;
            }
            if(visited[node->val] == true){
                return true;
            } else{
                res = res | dfs_helper(node->val, visited, s);
            }
        }
        return res;
    }

    bool UndirectedhasCycle(int s){
        vector<bool> visited(v+1, 0);
        visited[s] = true;
        bool hasCycle = dfs_helper(s, visited, 1);
        cout<< "Undirected cycle: "<<hasCycle<<endl;
        return hasCycle;
    }

};
void testUndirectedGraphCycle(){
    GraphRevision2 g(5);
    g.buildGraph();

    g.UndirectedhasCycle(1);
    
}