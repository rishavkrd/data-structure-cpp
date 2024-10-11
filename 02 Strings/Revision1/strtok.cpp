#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int main(){
    char* s;
    char input[1000];
    vector<string> tokens;
    cin.getline(input,1000);

    s = strtok(input, " ");
    while(s != NULL){
        tokens.push_back(s);
        s = strtok(NULL, " ");
    }
    for(auto token : tokens){
        cout<< token<<endl;
    }
    return 0;
}