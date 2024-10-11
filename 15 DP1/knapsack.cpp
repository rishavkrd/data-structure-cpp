#include<iostream>
#include<vector>

using namespace std;
int count = 0;
int knapsack(vector<int> wt, vector<int>prices, int w, int n, vector<vector<int>> &dp_mem){
	if(n<0 || w<=0){
		return 0;
	}
	if(dp_mem[w][n]!=-1){
		return dp_mem[w][n];
	}
	int inc = 0, exc =0;

	if(w>=wt[n]) inc = prices[n] + knapsack(wt, prices, w-wt[n], n-1, dp_mem);
	exc = knapsack(wt, prices, w, n-1, dp_mem);
	count++;
	cout<<w<<','<<n<<endl;
	return dp_mem[w][n] = max(inc, exc);

}

int knapsack_dp(vector<int> wt, vector<int> prices, int W){
	int N = prices.size();
	vector<vector<int>> dp(N+1, vector<int>(W+1, 0));

	for(int n=1;n<=N;n++){
		for(int w = 1; w<=W;w++){
			int inc =0, exc = 0;
			if(w - wt[n-1]>=0){
				inc = prices[n-1] + dp[n-1][w - wt[n-1]];
			}
			exc = dp[n-1][w];
			dp[n][w] = max(inc, exc);
		}
	}
	for(int i=0;i<=N;i++){
		for(int num : dp[i]){
			cout<<num<<' ';
		}
		cout<<endl;
	}
	return dp[N][W];
}

int knapsack_dp_opt(vector<int> wt, vector<int> prices, int W){
	int N = prices.size();
	vector<int> prev(W+1, 0);
	vector<int> dp(W+1, 0);

	for(int n=1;n<=N;n++){
		for(int w = 1; w<=W;w++){
			int inc =0, exc = 0;
			if(w - wt[n-1]>=0){
				inc = prices[n-1] + prev[w - wt[n-1]];
			}
			exc = prev[w];
			dp[w] = max(inc, exc);
		}
		prev = dp;
		// vector<int> temp (W+1, 0);
		// dp = temp;
	}
	for(int num : dp){
		// for(int num : dp[i]){
			cout<<num<<' ';
		// }
		cout<<endl;
	}
	return dp[W];
}

int main(){
	vector<int> weights = {2,7,3,4};
	vector<int> prices = {5,20,20,10};

	int N=4, W=11;
	vector<vector<int>> dp_mem(W+1, vector<int>(N, -1));
	// cout<<knapsack(weights, prices,W,N-1,dp_mem)<<endl;
	// cout<<count<<endl;
	cout<<knapsack_dp_opt(weights, prices,W)<<endl;
	return 0;
}