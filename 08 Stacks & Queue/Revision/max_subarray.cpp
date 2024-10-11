#include<iostream>
#include<deque>
#include<vector>

using namespace std;

void maxSubarray(vector<int> arr, int k){
    deque<int> history(k);

    //1. Process only the first K elements
    int i;

    for(i=0;i<k;i++){
        //Logic here ...

        while(!history.empty() && arr[i] > arr[history.back()]){
            history.pop_back();
        }

        history.push_back(i);

    }
    
    for(; i<arr.size(); i++){
        // cout<<arr[i]<<endl;
        cout<<arr[history.front()]<< " ";

        while(!history.empty() and history.front() <=i-k){
            history.pop_front();
        }
        while(!history.empty() && arr[i]>=arr[history.back()]){
            history.pop_back();
        }

        history.push_back(i);
    }
    cout<<arr[history.front()];
}

int main(){
    vector<int> arr = {1,2,3,1,4,5,2,3,6};
    int k = 3;

    maxSubarray(arr, k);
    return 0;
}