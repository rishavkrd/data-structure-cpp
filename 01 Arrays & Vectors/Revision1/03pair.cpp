#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

vector<int> pairsum(vector<int> arr, int sum){
    unordered_set<int> s;
    for(int n : arr){
        if(s.find(sum-n)!=s.end()){
            return {n, sum-n};
        } else{
            s.insert(n);
        }
    }
    return {-1, -1};

}

int main(){
    vector<int> arr{10, 5, 2 , 3, -8, 9 , 11};
	int S = 4;
    vector<int> ans = pairsum(arr, S);
    cout << ans[0] << "," << ans[1];
    return 0;
}