#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

char* mystrtok(char* str, char delim){
    static char* input;
    if(str!=NULL) input = str;
    if(input==NULL) return NULL;

    int i = 0;
    char *token = new char[strlen(input)+1];
    for(;input[i]!='\0';i++){
        if(input[i]!=delim){
            token[i] = input[i];
        } else{
            input = input + i + 1;
            token[i] = '\0';
            return token;
        }
    }
    token[i] = '\0';
    input = NULL;
    return token;
}

int main(){

    char input[1000];
    cin.getline(input,1000);

   //strtok()
     // char *token =  strtok(input," ");
     

     // while(token!=NULL){
     //    cout<<token <<endl;
     //    token = strtok(NULL," ");
     // }

    char* token = mystrtok(input, ' ');
    while(token!=NULL){
        cout<<token<<endl;
        token = mystrtok(NULL, ' ');
    }


    return 0;
}