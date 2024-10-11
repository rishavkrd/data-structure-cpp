#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool isOOO(int i, vector<int> arr){

    if(i!=arr.size()-1 && arr[i]>arr[i+1]){
        return true;
    }
    if(i!=0 && arr[i]<arr[i-1]){
        return true;
    }
    return false;
}

pair<int,int> subarraySort(vector<int> arr){
    int smallest=INT_MAX, largest=INT_MIN;
    for(int i=0; i<arr.size(); i++){
        if(isOOO(i, arr)){
            smallest = min(smallest, arr[i]);
            largest = max(largest, arr[i]);
            cout<<smallest<<" ---- "<<largest << endl;
        }
    }
    int left_index=0, right_index = arr.size()-1;
    
    if(smallest==INT_MAX || largest==INT_MIN){
        return {-1,-1};
    }
    while(smallest>=arr[left_index]){
        left_index++;
    }
    while(largest<=arr[right_index]){
        right_index--;
    }
    return {left_index, right_index};
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    auto p = subarraySort(arr);
    cout<< p.first <<" and "<<p.second <<endl;

    return 0;
}