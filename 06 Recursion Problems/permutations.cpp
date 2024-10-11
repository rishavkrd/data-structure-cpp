#include<bits/stdc++.h>
#include<set>
using namespace std;

void swap(string &s, int a, int b){
    char temp = s[a];
    s[a]=s[b];
    s[b] = temp;
    return;
}

void helper(set<string> &set, string s, int idx){
    if(idx == s.length()-1){
        cout<<s<<endl;
        // res.push_back(s);
        set.insert(s);
        return;
    }
    for(int i=idx; i<s.length(); i++){
        swap(s, idx, i);
        helper(set, s, idx+1);
        // swap(s, idx, i);
    }
    return;
}

vector<string> findSortedPermutations(string s){
    //Your code goes here. Do not change the function or parameters. You can use helper functions if needed.
    vector<string> res;
    set <string> set;
    helper(set, s, 0);
    res.insert(res.end(), set.begin(), set.end());
    return res;
}


int main(){

	string s;
	cin>>s;
	findSortedPermutations(s);
	return 0;
}