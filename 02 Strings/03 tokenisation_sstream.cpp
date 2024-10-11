#include<iostream>
#include<sstream>
#include<vector>
#include<cstring>
using namespace std;


int main(){

	// string input;
	// getline(cin,input);
	// //"this is a sunny day"

	// //create a string stream object
	// stringstream ss(input);

	// // >> and << operators 
	// string token;
	// vector<string> tokens;
	// while(getline(ss,token,' ')){
	// 	tokens.push_back(token);
	// }

	// //print all all tokens
	// for(auto token:tokens){
	// 	cout<<token<<",";
	// }

	string input;
	getline(cin, input);

	string token;
	vector<string> tokens;

	stringstream ss(input);

	while(getline(ss, token, ' ')){
		tokens.push_back(token);
	}

	for(auto token : tokens)	
		cout<<token<<',';
	
	


	return 0;
}