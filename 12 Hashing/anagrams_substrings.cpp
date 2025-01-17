#include<iostream>
#include<map>
#include<vector>
using namespace std;

/*
1. Generate all substrings
2. Generate their hash
3. Hash the 'hash' values to club all anagrams in single bucket, to get their frequency count
4. From freq count, we can easily count the paris  
*/
// vector<int> getHashValue(string s,int i,int j){

// 	vector<int> freq(26,0);

// 	//iterate over the original string from i to j to fill this vector
// 	for(int k=i;k<=j;k++){
// 		char ch = s[k];
// 		freq[ch-'a']++;
// 	}

// 	return freq;

// }



// int anagrams_substrings(string s){

// 	map<vector<int> , int > m;

// 	for(int i=0;i<s.length();i++){
// 		for(int j=i; j<s.length();j++){

// 			//Substring S[i...j]
// 			vector<int> h = getHashValue(s,i,j);
// 			//put it inside a map
// 			m[h]++;
// 		}
// 	}

// 	//pairs
// 	int ans = 0;
// 	for(auto p : m){

// 		int freq = p.second;
// 		if(freq>=2){
// 			ans += (freq)*(freq-1)/2;
// 		}

// 	}
// 	return ans;

// }

int nC2(int f){
	return f*(f-1)/2;
}

int anagrams_substrings(string s){
	// vector<string> substrings;
	vector<int> arr(26,0);
	map<vector<int>,int> ht;

	for(int i=0; i<s.size(); i++){
		for(int j=i; j<s.size(); j++){
			string substr = s.substr(i,j-i+1);
			// substrings.push_back(substr);
			// cout<<substr<<endl;
			for(char c : substr){
				arr[c-'a']++;
			}
			ht[arr]++;
			fill(arr.begin(), arr.end(), 0);
		}
	}
	int res=0;
	for(auto x : ht){
		// cout<<x.second<<endl;
		int pairs = nC2(x.second);
		res+=pairs;
	}

	return res;

}


int main(){

	string s;
	cin>>s ;
	cout<<"working"<<endl;
	cout<<anagrams_substrings(s)<<endl;


	return 0;
}