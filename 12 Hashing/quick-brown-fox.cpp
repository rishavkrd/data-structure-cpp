#include <iostream>
#include<unordered_set>
#include<climits>
using namespace std;


string s ="thequickbrownfoxjumpsoverthehighbridge";

string words[] = {"the","fox","thequickbrownfox", "jumps","lazy","lazyfox",

					"highbridge","the","over", "bridge","high","tall",

					"quick","brown"};

/*
string s ="thequickbrownfox";

string words[] = {"the", "quickbrown", "fox","quick","brown"};
*/
//Main Logic
// int min_bars_helper(string s,string words[],int idx, unordered_set<string> &m){

// 	//base case
// 	if(s[idx]=='\0'){
// 		return 0;
// 	}

// 	//rec case
// 	int ans = INT_MAX;
// 	string current_string = "";

// 	for(int j=idx; s[j]!='\0';j++){
// 		current_string += s[j];

// 		//at every step you can whether this prefix is present in set 
// 		if(m.find(current_string)!=m.end()){
// 			int remaning_ans = min_bars_helper(s,words,j+1,m);
// 			if(remaning_ans!=-1){
// 				ans = min(ans, 1 + remaning_ans);

// 			}
// 		}
// 	}

// 	if(ans==INT_MAX){
// 		return -1;
// 	}
// 	return ans;
// }



// int min_bars(){

// 	unordered_set<string> m;

// 	for(string w:words){
// 		m.insert(w);
// 	}

// 	//recursive helper function 
// 	int output = min_bars_helper(s,words,0,m);
// 	return output - 1;

// }

int min_bars_helper(string str, unordered_set<string> set, int idx){
	if(idx==str.length()) return -1;

	string substr = "";
	int end =1;
	while(set.find(substr)==set.end()){
		substr = str.substr(idx,end++);
	}
	int inc = min_bars_helper(str,set,end)+1;
	int not_inc = min_bars_helper(str,set,idx);

	if(inc!=-1 or not_inc!=-1) return min(inc,not_inc);
	
}

int min_bars(){
	unordered_set<string> m;
	for(string w : words){
		m.insert(w);
	}

	int output = min_bars_helper(s, m);
}

int main(){

	cout<< min_bars() <<endl;

	return 0;
}

