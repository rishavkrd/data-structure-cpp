#include<iostream>
#include<vector>
#include<climits>

using namespace std;
vector<int>dp;
int array_jump(vector<int> arr, int idx){
	int n = arr.size();
	if(idx == n-1){
		return 0;
	}
	if(dp[idx]!=-1){
		return dp[idx];
	}
	int min_jump = INT_MAX;
	// cout<<"min: "<<min_jump<<endl;
	for(int i = idx+1; i<=idx+arr[idx] && i<n; i++){
		int jump = array_jump(arr, i) + 1;
		min_jump = min(min_jump, jump);
		// cout<<min_jump<<" --min ; jump: "<<jump<<endl;
	}
	return dp[idx] = min_jump;


}

int array_jump_dp(vector<int> arr){
	vector<int> cache(arr.size(),INT_MAX);
	cache[0] = 0;
	for(int i=0; i<arr.size();i++){
		int currentjump = cache[i];
		for(int j=i+1;j<=i+arr[i] ; j++){

			cache[j] = min(1 + currentjump, cache[j]);
			if(j==arr.size()-1) return cache[j];
		}
	}
	return -1;
}

int main(){
	vector<int> arr = {3,4,2,1,2,3,4,1,1,1,2,5};
	vector<int> temp (arr.size(), -1);
	dp = temp;
	cout<<array_jump_dp(arr)<<endl;
	cout<<array_jump(arr,0)<<endl;
	return 0;
}