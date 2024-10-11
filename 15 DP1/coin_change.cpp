#include<iostream>
#include<vector>
#include<climits>

using namespace std;
vector<int>dp(1000,-1);
int coin_change(int n, vector<int> coins){
	if(n == 0){
		return 0;
	}
	if(n<0){
		return -1;
	}
	if(dp[n]!=-1){
		// cout<<dp[n]<<" dp: "<<n<<endl;
		return dp[n];
	}
	int min_coin = INT_MAX;
	for(int coin : coins){
		if(n-coin>=0){
			int num = coin_change(n-coin, coins);
			if(num!=-1){
				cout<<num+1<<" value: "<<n<<endl;
				min_coin = min(min_coin, num+1);
			} 			
		}
	}
	if(min_coin==INT_MAX) return -1;
	return dp[n] = min_coin;
}
int dp_coin_change(int n, vector<int> coins){
	vector<int> dp2 (n+1, INT_MAX);
	dp2[0]=0;

	for(int i=1;i<=n;i++){

		for(int coin : coins){
			if(i-coin>=0 && dp2[i-coin]!=INT_MAX){
				dp2[i] = min(dp2[i], dp2[i-coin]+1);
				cout<<dp2[i]<<" coins to make "<<i<<endl;
			}
		}
	}
	return dp2[n]==INT_MAX? -1 : dp2[n];

}
int main(){
	vector<int> coins = {1,3,7,10};
	int n;
	cin>>n;

	cout<<dp_coin_change(n,coins)<<" -- min_coins"<<endl;



	return 0;
}