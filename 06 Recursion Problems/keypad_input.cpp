#include<iostream>
#include<cstring>
using namespace std;

string keypad[] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};


// void printKeypadOutput(string input,string output,int i=0){

// 	if(input[i]=='\0'){
// 		cout<<output<<endl;
// 		return;
// 	}

// 	//rec case
// 	int current_digit = input[i] - '0';
// 	if(current_digit==0 or current_digit==1){
// 		printKeypadOutput(input,output,i+1);
// 	}

// 	//keypad 
// 	for(int k=0; k<keypad[current_digit].size();k++){
// 		printKeypadOutput(input,output + keypad[current_digit][k],i+1);
// 	}
// 	return;

// }

void printKeypadOutput(string input, string output){
	if(input == ""){
		cout<<output<<endl;
		return;
	}

	int num = input[0] - '0';
	input = input.substr(1);
	if(num == 0 || num ==1){
		printKeypadOutput(input, output);
	}
	for(char c : keypad[num]){
		printKeypadOutput(input, output+c);
	}
}




int main(){

	string input;
	cin>>input;

	string output;
	printKeypadOutput(input,output);


	return 0;
}