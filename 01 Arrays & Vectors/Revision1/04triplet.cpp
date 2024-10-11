#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

vector<vector<int>> triplet(vector<int> arr, int sum){
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;
    for(int i=0; i<arr.size()-2; i++){
        
        int l=i+1, r=arr.size()-1;
        while(l<r){
            int s = arr[i] + arr[l] + arr[r];
            if(s==sum){
                result.push_back({arr[i],arr[l],arr[r]});
                l++;
            } else if(s>sum){
                r--;
            } else{
                l++;
            }
        }
    }
    return result;
}

int main(){
    vector<int> arr{1, 11, 2, 3, 4, 5, 6, 7, 8, 9, 15};
	int S = 18;

    vector<vector<int>> results = triplet(arr, S);
    
    for(auto res : results){
        cout << res[0] << "," << res[1] <<","<< res[2] << endl;
    }

    return 0;
}