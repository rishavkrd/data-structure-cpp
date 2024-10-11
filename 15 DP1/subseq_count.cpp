#include<iostream>
#include<vector>
#include<string>

using namespace std;
vector<vector<int>> dp_mem(100,vector<int>(100,-1));
int subseq_count(string s1, string s2, int i, int j){
	if(j == s2.length()) return 1;
	if(i==s1.length() || s1.length()-i<s2.length()-j){
		return 0;
	}
	if(dp_mem[i][j]!=-1) return dp_mem[i][j];
	int count = 0;
	count += subseq_count(s1,s2, i+1, j);
	if(s1[i]==s2[j]) count += subseq_count(s1, s2, i+1, j+1);
	return dp_mem[i][j] = count; 

}
int subseq_count_dp(string s1, string s2){
	int n = s1.length(), m = s2.length();
	vector<vector<int>> dp (n+1, vector<int>(m+1, 0));

	for(int i = 0; i<=n; i++){
		dp[i][0] = 1;
	}
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m;j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
			} else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][m];
}

int main(){
	string s1 = "ABCDCEGCC";
	string s2 = "ABC";
	cout<<subseq_count(s1, s2, 0,0)<<endl;
	cout<<subseq_count_dp(s1, s2)<<endl;
	return 0;
}