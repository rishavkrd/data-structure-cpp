#include<iostream>
#include<vector>

using namespace std;

int main(){
	int n;
	cin>>n;

	vector<int> dp(n+1, 0);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	for(int i=3;i<=n;i++){
		int sum = 0;
		for(int j=0;j<i;j++){
			sum += dp[j] * dp[i-j-1];
		}
		dp[i] = sum;
	}
	cout<<dp[n]<<endl;
	return 0;
}