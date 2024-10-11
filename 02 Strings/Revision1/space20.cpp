#include<iostream>
#include<cstring>

using namespace std;

int space_counts(char inp[]){
    string input(inp);
    int index = input.find(' ');
    int space_count = 0;
    while(index!=-1){
        space_count++;
        index = input.find(' ', index+1);
    }
    return space_count;
}

void replace_space(char *input){
    int extra = space_counts(input)*2;
    for(int i=strlen(input)-1; i>=0; i--){
        if(input[i]!=' '){
            input[i+extra] = input[i];
            
        } else{
            input[i+extra] = '0';
            input[i+extra-1] = '2';
            input[i+extra-2] = '%';
            extra -= 2;
        }
    }
}


void replace_space2(char *inp){
     int n=0, s = 0;
     while(inp[n]!=0){
        n++;
        if(inp[n] == ' '){
            s++;
        }
     }
     int i = n + 2*s ;
    cout<<"size: "<<n<<endl;

    while(i>=0){
        if(inp[n] != ' '){
            inp[i] = inp[n];
            i--; n--;
        }
        else{
            inp[i--] = '0';
            inp[i--] = '2';
            inp[i--] = '%';
            n--;
            
        }
        cout<<i<<","<<n<<endl;
    }

}

int main() {
    char input[10000];
    cin.getline(input,1000);
    replace_space2(input);
    cout<<input <<endl;

    return 0;
}