// CODING INTERVIEW ~ 20 mins

// FROG JUMPS
// ============
// Given an array containing integers, and there is a frog 
// sitting at the starting of the array. Each integer represents the 
// maximum number of steps frog can take in the array.
// Write a function which can calculates the minimum jumps 
// required by frog to reach the end of the array.


#include<iostream>
#include<vector>
#include<climits>

using namespace std;

vector<int> dp;

int frog_jump(vector<int> arr, int idx){
	if(idx>= arr.size()){
		return INT_MAX;
	}
	if(idx == arr.size()-1) return 0;

	if(dp[idx]!=-1) return dp[idx];

	int onejump = INT_MAX;
	if(idx<arr.size()-1) onejump = frog_jump(arr, idx+1) + abs(arr[idx]-arr[idx+1]);
	int twojump = INT_MAX;
	if(idx<arr.size()-2) twojump = frog_jump(arr, idx+2) + abs(arr[idx]-arr[idx+2]);

	return dp[idx] = min(onejump, twojump);
}

int frog_jump_dp(vector<int> arr){
	int n = arr.size();
	vector<int> cache(n,INT_MAX);
	cache[0]=0;

	for(int i=0;i<n;i++){
		int current_cost = cache[i];
		if(i<n-1){
			int cost = current_cost + abs(arr[i]-arr[i+1]);
			cache[i+1] = min(cache[i+1], cost);
		}
		if(i<n-2){
			int cost = current_cost + abs(arr[i]-arr[i+2]);
			cache[i+2] = min(cache[i+2], cost);
		}
	}
	return cache[n-1];
}

int main(){
	vector<int> arr = {10, 30, 40, 20};
	vector<int> temp (arr.size(), -1);
	dp = temp;
	cout<<frog_jump(arr, 0)<<endl;
	cout<<frog_jump_dp(arr)<<endl;
	return 0;
}

