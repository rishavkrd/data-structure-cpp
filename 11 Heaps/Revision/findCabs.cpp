#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

void smallestK(vector<int> arr, int k){
    priority_queue<int, vector<int>> maxHeap(arr.begin(), arr.begin()+k);

    for(int i=k; i<arr.size(); i++){
        if(arr[i]<maxHeap.top()){
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }
    while(!maxHeap.empty()){
        cout<<maxHeap.top()<<", ";
        maxHeap.pop();
    }

}

int main(){
    vector<int> arr = {5,3,4,7,8,9,1,2,6};
    int k = 5;
    smallestK(arr,k);
    return 0;
}