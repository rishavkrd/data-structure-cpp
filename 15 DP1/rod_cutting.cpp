#include<iostream>
#include<climits>
using namespace std;


//Recursive Solution
int max_profit(int prices[],int n){
	//base case
	if(n<=0){
		return 0;
	}

	//rec case
	int ans = INT_MIN;

	for(int i=0;i < n;i++){
		int cut = i + 1;

		int current_ans = prices[i] + max_profit(prices,n - cut);
		ans = max(ans,current_ans);

	}
	return ans;
}



//bottom up solution
int max_profit_dp(int *prices,int n){

	int dp[n+1];
	dp[0] = 0;


	for(int len=1;len<=n;len++){

		int ans = INT_MIN;
		for(int i=0;i<len;i++){
			int cut = i + 1;
			int current_ans = prices[i] + dp[len - cut];
			ans = max(current_ans,ans);
		}
		//computed the ans for dp[len]
		dp[len] = ans;

	}

	return dp[n];
}

int max_profit2(int prices[], int n){
	if(n<=0) return 0;
	int ans = INT_MIN;
	for(int i=0;i<n;i++){
		ans = max(ans, max_profit2(prices, n-i-1) + prices[i]);
	}
	return ans;
}

int max_profit_dp2(int prices[], int n){
	int ans = INT_MIN;
	int dp[n+1];
	dp[0] = 0;
	for(int len = 1; len<=n; len++){
		int price=INT_MIN;
		for(int i=len; i>0;i--){
			int cut = i-1;
			price = max(price, prices[cut] + dp[len - i]);
		}
		dp[len] = price;
		ans = max(dp[len], ans);
	}
	return ans;

}


int main(){

	int prices[] = {3, 5, 8, 9, 10, 17, 17, 20};
	int n = sizeof(prices)/sizeof(int);

	cout<< max_profit_dp2(prices,n)<<endl;


	return 0;
}