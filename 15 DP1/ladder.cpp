#include<iostream>
#include <vector>
using namespace std;

//approach 1 Rec + Memo

vector<int> dp;
int dfs(int n, int k){

	if (n == 0 or n==1){
		return 1;
	}
	if(dp[n]!=-1){
		return dp[n];
	}
	int paths = 0;
	for(int i=1;i<=k;i++){
		if(n-i>=0) paths += dfs(n-i, k);
	}
	dp[n] = paths;
	cout<<"n: "<<n<<" paths: "<<paths<<endl;
	return dp[n];
}

int bottom_up(int n, int k){
	vector<int> arr(n+1, 0);
	arr[0]=1;
	arr[1]=1;

	for(int i = 2; i<=k; i++){
		for(int j = i-1; j>=0; j--){
			arr[i]+=arr[j];
		}
	}

	for(int i = k+1; i<=n; i++){
		// for(int j = i-1; j>=0 && j>=i-k; j--){		//O(K) - How to reduce it to O(1)?
		// 	arr[i]+=arr[j];
		// }
		arr[i] = 2*arr[i-1] - arr[i-1-k];
	}
	return arr[n];
}

int main(){
	int n, k;
	cin>>n;
	cin>>k;
	vector<int> temp(n+1, -1);
	dp = temp;
	cout<< bottom_up(n, k)<<endl;
	return 0;
}