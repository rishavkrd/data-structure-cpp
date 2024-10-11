#include <iostream>
#include<cstring>
using namespace std;

// void replace_space(char *str){

//     //1. calc spaces 
//     int spaces = 0;
//     for(int i=0;str[i]!='\0';i++){
//         if(str[i]==' '){
//             spaces += 1;
//         }
//     }

//     int idx = strlen(str) + 2*spaces;
//     str[idx] = '\0';

//     for(int i= strlen(str)-1;i>=0;i--){
//         if(str[i]==' '){
//             str[idx-1] = '0';
//             str[idx-2] = '2';
//             str[idx-3] = '%';
//             idx = idx - 3;
//         }
//         else{
//             str[idx-1] = str[i];
//             idx--;
//         }
//     }

// }

void replace_space(char *str){
    int n = 0;
    int len = strlen(str);
    for(int i=0; i<len; i++){
        if(str[i] == ' ') n++;
    }
    n *= 2;
    str[len + n] = '\0';
    int end = len + n - 1;
    for(int i= end; i>=0; i--){

        if(str[i-n] != ' ') str[i] = str[i-n];
        else {
            str[i--] = '0';
            str[i--] = '2';
            str[i] = '\%';
            n -= 2;
        }

    }
}


int main() {
    char input[10000];
    cin.getline(input,1000);
    replace_space(input);
    cout<<input <<endl;

    return 0;
}
