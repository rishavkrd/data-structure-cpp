#include<iostream>
#include<string>

using namespace std;

int main(){
    string paragraph = "I live in the US. US is a very big country.";
    string word;
    getline(cin, word);
    int index = paragraph.find(word);
    while(index!=-1){
        cout<<"Occurence: " << index<<endl;
        index = paragraph.find(word, index+1);
    }
    return 0;
}