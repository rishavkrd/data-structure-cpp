#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> triplet(vector<int> arr, int sum){
    sort(arr.begin(), arr.end());

    vector<vector<int>> results;
    int n = arr.size();
    for(int i=0; i<n-2; i++){
        int l = i+1, r = n-1;
        while(l<r){
            if(arr[l]+arr[r] == sum - arr[i]){
                results.push_back({arr[i], arr[l], arr[r]});
                l++;
            }
            else if(arr[l]+arr[r] > sum - arr[i]){
                r--;
            }
            else{
                l++;
            }
        }
    }
    return results;
}

vector<vector<int>> triplet2(vector<int> arr, int sum){
    sort(arr.begin(), arr.end());
    vector<vector<int>> set;

    for(int i=0; i<arr.size(); i++){
        int l=i+1,  r=arr.size()-1;
        while(l<r){
            int currSum = arr[i]+arr[l]+arr[r];
            if(currSum == sum){
                set.push_back({arr[i], arr[l], arr[r]});
                l++;
            } else if(currSum > sum){
                r--;
            } else{
                l++;
            }
        }

    }
    return set;
}

int main(){
    vector<int> arr{1, 11, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    int S = 15;

    vector<vector<int>> results = triplet2(arr, S);
    
    for(auto res : results){
        cout << res[0] << "," << res[1] <<","<< res[2] << endl;
    }

    return 0;
}