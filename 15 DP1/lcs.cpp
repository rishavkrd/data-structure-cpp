#include<iostream>
#include<vector>
#include<string>

using namespace std;

int lcs(string s1, string s2, int i, int j){
	if(i>=s1.length() || j >=s2.length()){
		return 0;
	}
	int res = 0;
	if(s1[i]==s2[j]){
		res = 1 + lcs(s1, s2, i+1, j+1);
	}
	else{
		res = max(lcs(s1, s2, i+1, j), lcs(s1, s2, i, j+1));
	}
	return res;
}

int lcs_dp(string s1, string s2){
	vector<vector<int>> dp (s1.length()+1, vector<int>(s2.length()+1,0));

	for(int i = 1; i<=s1.length(); i++){
		for(int j = 1; j<=s2.length(); j++){
			if(s1[i]==s2[j]) dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	for(int i=0;i<s1.length();i++){
		for(int j : dp[i]){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return dp[s1.length()] [s2.length()];
}

int main(){
	string s1 = "ABACD";
	string s2 = "AABEDG";

	cout<<lcs(s1, s2, 0,0)<<endl;
	cout<<lcs_dp(s1, s2)<<endl;

	return 0;
}