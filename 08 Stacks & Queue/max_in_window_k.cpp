#include <iostream>
#include<vector>
#include<deque>
using namespace std;

void maxSubArrayK(vector<int> a,int k){

    //Algorithm
    int n = a.size();

    deque<int> Q(k);
    //1. Process only the first K elements
    int i;

    for(i=0;i<k;i++){
        //Logic here ...

        while(!Q.empty() && a[i] > a[Q.back()]){
            Q.pop_back();
        }

        Q.push_back(i);

    }

    //2. Remaining the elements of the array
    for( ;i<n;i++){
        cout << a[Q.front()]<<" ";
        //Remove element from the left (contraction when an index lies outside the current window)
        while(!Q.empty() and Q.front() <=i-k){
            Q.pop_front();
        }
        while(!Q.empty() && a[i] >= a[Q.back()]){
            Q.pop_back();
        }

        //always
        Q.push_back(i);
    }


    cout<< a[Q.front()];

}

void maxSubArrayK2(vector<int> arr, int k){ //Bug: does not give biggest when window expires.
    deque<int> kings;
    int age = 0;
    for(int i=0;i<k;i++){
        if(kings.empty()) {
            kings.push_back(arr[i]);
            age++;
        }
        else{
            if(kings.front()<arr[i]){
                kings.clear();
                age = 0;
            } 
            kings.push_back(arr[i]);
            age++;
        }
    }

    cout<<kings.front()<< ' ';

    for(int i=k; i<arr.size(); i++){
        if(age == k){
            kings.pop_front();
            age--;
        }
        if(kings.front()<arr[i]){
            kings.clear();
            age = 0;
        } 
        kings.push_back(arr[i]);
        age++;
        cout<<kings.front()<<' ';
    }
    return;
}

int main() {
    
    // vector<int> arr{1,2,3,1,4,0,1,0,3,4};
    vector<int> arr = {1,2,3,1,4,5,2,3,6};
    int k = 3;

    maxSubArrayK(arr,k);


    
    
    return 0;
}