#include<iostream>
#include<string>
#include<stack>
using namespace std;

// bool checkRedundant(string str){
// 	//Complete
// 	stack<char> s;

// 	for(char ch : str){
// 		if(ch!=')'){
// 			s.push(ch); // a,b, + , - , ( ....
// 		}
// 		else{
// 			// ')'
// 			bool operator_found = false;

// 			while(!s.empty() and s.top()!='('){
// 				char top = s.top();
// 				if(top=='+' or top=='-' or top=='*' or top=='/'){
// 					operator_found = true;
// 				}
// 				s.pop();
// 			}
// 			s.pop(); //pop the opening bracked after the loop if over

// 			if(operator_found == false){
// 				return true;
// 			}
// 		}
// 	}
// 	return false;
// }

bool checkRedundant(string str){
	stack<char> s;
	bool opt = false;
	bool opr = false;
	for(char c : str){
		if(c != ')') s.push(c);
		else{
			while(s.top()!='('){
				char top = s.top();
				if(top == '+' or top == '-' or top == '/' or top == '*') opt = true;
				else opr = true;

				s.pop();
			}
			if(opr && opt){
				s.pop();
				opr=false;
				opt=false;
			} else{
				return true;
			}
		}
	}
	return false;
}


int main() {
    string str = "((a+b)+c) + (d*e)";
    if(checkRedundant(str)){
        cout<<"Contains Redundant Parenthesis"<<endl;
    }
    else{
        cout<<"Not Redundant"<<endl;
    }
    return 0;
}
