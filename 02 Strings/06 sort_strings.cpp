/*
Sample Input
------------
3
92 022
82 12
77 13
2 false numeric

Sample Output
-------------
82 12
77 13
92 022

*/
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

// string extractStringAtKey(string str,int key){

// 	//string tokeniser 
// 	// hello how are you

// 	char *s = strtok( (char *)str.c_str(), " ");
// 	while(key>1){
// 		s = strtok(NULL," ");
// 		key--;
// 	}
// 	return (string)s;
// }

// int convertToInt(string s){

// 	int ans = 0;
// 	int p = 1;

// 	for(int i=s.length()-1; i>=0;i--){
// 		ans += ((s[i]-'0')*p);
// 		p = p*10;
// 	}
// 	return ans;
// }

// bool lexicoCompare(pair<string,string> s1, pair<string,string> s2){
// 	string key1, key2;
// 	key1 = s1.second;
// 	key2 = s2.second;
// 	return key1 < key2;
// }

// bool numericCompare(pair<string,string> s1, pair<string,string> s2){
// 	string key1, key2;
// 	key1 = s1.second;
// 	key2 = s2.second;

// 	return convertToInt(key1) < convertToInt(key2);
// }






// int main(){
// 	string s ="20 30 40 50";
	
	
// 	int n;
// 	cin>>n;

// 	cin.get(); //consume the extra \n

// 	string temp;
// 	vector<string> v;
// 	for(int i=0;i<n;i++){
// 		getline(cin,temp); //includes white spaces 
// 		v.push_back(temp);
// 	}

// 	int key;
// 	string reversal,ordering;
// 	cin >>key >> reversal >> ordering; 


// 	//1. To extract keys for comparison & store them
// 	vector<pair<string,string> > vp;  

// 	for(int i=0;i<n;i++){
// 		vp.push_back({v[i], extractStringAtKey(v[i],key)});
// 	}

// 	//2. Sorting 
// 	if(ordering=="numeric"){
// 		sort(vp.begin(),vp.end(),numericCompare);
// 	}
// 	else{
// 		sort(vp.begin(),vp.end(),lexicoCompare);
// 	}


// 	//3. reversal
// 	if(reversal=="true"){
// 		reverse(vp.begin(),vp.end());
// 	}

// 	//4. output
// 	for(int i=0;i<n;i++){
// 		cout<< vp[i].first << endl;
// 	}



// 	return 0;
// }

vector<string> extractKeys(vector<string> inputs, int col){
	vector<string> res;
	for(string s : inputs){
		string temp = strtok((char *)s.c_str(), " ");
		for(int i=1; i<col; i++){
			temp = strtok(NULL, " ");
		}
		res.push_back(temp);
	}
	return res;
}

int compareLexo(pair<string, string> ps1, pair<string,string> ps2){
	string a = ps1.first, b = ps2.first;
	return a<b;
}
int toint(string a){
	int ans=0;
	int p=1;
	for(int i=a.length()-1;i>=0;i--){
		ans+=((a[i] - '0')*p);
		p*=10;
	}
	return ans;
}
int compareNumeric(pair<string, string> ps1, pair<string,string> ps2){
	string a = ps1.first;
	string b = ps2.first;
	int n1 = toint(a);
	int n2 = toint(b);

	return n1<n2;
}

int main(){
	string s;
	vector<string> inputs;
	int n;
	cin>>n;	//doesnt include white space
	cin.get();	//consume the endl
	for(int i=0;i<n;i++){
		getline(cin, s);	//includes white spaces
		inputs.push_back(s);
	}
	int col;
	string reversal, ordering;
	cin>>col>>reversal>>ordering;
	// cin.get();
	vector<string> keys;

	keys = extractKeys(inputs, col);
	cout<<"extracted keys "<<keys[0]<<endl;
	vector<pair<string, string>> sp;

	for(int i=0; i<n; i++){
		// pair<string, string> temp;
		// temp.first = keys[i];
		// temp.second = inputs[i];
		sp.push_back({keys[i],inputs[i]});
		cout<<"pushed "<< sp[i].first<<endl;
	}

	if(ordering == "numeric"){
		cout<<"numeric sort"<<endl;
		sort(sp.begin(), sp.end(), compareNumeric);
	} else{
		sort(sp.begin(), sp.end(), compareLexo);
	}

	if(reversal == "true"){
		reverse(sp.begin(), sp.end());
	}

	for(auto i : sp){
		cout<<i.second<<endl;
	}

	return 0;
}



