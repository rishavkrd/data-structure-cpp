#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

bool isAsubSequence(string s, string pattern){
    int index = -1;
    for(int i=0; i<pattern.size(); i++){
        char c = pattern[i];
        index = s.find(c,index+1);
        // cout<<index<<endl;
        if(index == -1){
            return false;
        }
    }
    return true;
}

vector<string> subseqSorted;
void sortSubsequence(string in, string out){
    if(in == "") {
        subseqSorted.push_back(out);
        return;
    }
    sortSubsequence(in.substr(1), out+in[0]);
    sortSubsequence(in.substr(1), out);

    return;

}

void sortSubseq2(string in, string out){
    if(in==""){
        subseqSorted.push_back(out);
        return;
    }
    sortSubseq2(in.substr(1), out + ""+in[0]);
    sortSubseq2(in.substr(1), out);

}

int main(){
    bool subSeq = isAsubSequence("ahkgbmxcd", "axc");
    cout<<"is Sub Sequence? "<< subSeq<<endl;

    cout<<"Sorted SUbsequence"<<endl;
    sortSubseq2("abcd", "");
    sort(subseqSorted.begin(), subseqSorted.end());
    for(auto s : subseqSorted){
        cout<<s<<endl;
    }


    return 0;
}