#include <iostream>
#include<vector>
#include<algorithm>
#include <map>
#include <unordered_set>
using namespace std;

// int countMinSwaps(vector<int> arr){

//     // Know the actual positions of elements (sorting)
//     //store the current indices
//     int n = arr.size();
//     pair<int,int> ap[n];
//     for(int i=0;i<n;i++){
//         ap[i].first = arr[i];
//         ap[i].second = i;
//     }

//     //sorting
//     sort(ap,ap+n);

//     //build the main logic
//     vector<bool> visited(n,false);

//     int ans = 0;
//     for(int i=0;i<n;i++){

//         // if element is visited or element is in right postion 
//         int old_position = ap[i].second;
//         if(visited[i]==true or old_position==i){
//             continue;
//         }

//         // visiting the element (index) for first time 
//         int node = i;
//         int cycle = 0;

//         while(!visited[node]){
//             visited[node] = true;
//             int next_node = ap[node].second;
//             node = next_node;
//             cycle += 1;
//         }
//         ans += (cycle-1);

//     }
   
//     return ans;

// }

int countMinSwaps(vector <int> arr){
    vector <int> arr2;
    unordered_set<int> s;
    map<int,int> pos;
    int res =0;


    for(int i=0; i<arr.size(); i++){
        arr2.push_back(arr[i]);
    }
    sort(arr2.begin(), arr2.end());
    for(int i=0; i<arr2.size(); i++){
        pos[arr2[i]]=i;
    }
    for(int i=0; i<arr.size(); i++){
        if(s.find(arr[i]) == s.end()){
            s.insert(arr[i]);
            int index = pos[arr[i]];
            int cycle_start = arr[i];
            int count=0;
            while(arr[index] != cycle_start){
                s.insert(arr[index]);
                index = pos[arr[index]];
                count++;
                
            }
            res+=count;
        }
    }
    
    return res;
}

int main() {
    // vector<int> arr{5,4,3,2,1};
    vector<int> arr{10,11,5,4,3,2,1};
    cout<<countMinSwaps(arr)<<endl;
    return 0;
}
