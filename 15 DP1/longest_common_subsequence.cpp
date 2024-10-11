#include<iostream>
#include<vector>
#include<string>

using namespace std;
string output = "";
vector<string>dp(100,"");
//doesnt work with DP since you need to maintain both index of i, j for the answers,
//because the results are unique to combination of i, j and not just on one index.
string lcs(string s1, string s2, int idx, string subseq){
	string res = "";
	if(idx == -1 ){
		return "";
	}
	// if(dp[idx]!=""){
	// 	return dp[idx];
	// }
	if(idx >= s2.length()){
		cout<<subseq<<endl;
		if(output.length()<subseq.length()) output = subseq;
		return subseq;
	}

	for(int i =0; i<s1.length(); i++){
		char c = s1[i];
		if(s2.find(c,idx)!=-1){
			int pos = s2.find(c,idx);
			// cout<<pos<<endl;
			string s = lcs(s1.substr(i), s2, pos+1, subseq+c);
			if(s.length()>res.length()){
				res = s;
			}
		}
	}
	
	return res;
}

int main(){
	string s1 = "ABCDE";
	string s2 = "BCAD";
	// vector<string> temp()
	lcs(s1, s2, 0, "");
	cout<<output<<endl;

	return 0;
}