#include<iostream>
#include<string>

using namespace std;

pair<int,int> smallest_window(string big, string small){
    pair<int,int> window = {-1,-1};
    int l=0,r=0;
    int count = 0, min_length = INT_MAX;
    int freqBig[26] = {};
    int freqSmall[26] = {};
    for(char c : small){
        freqSmall[c-'a']++;
        cout<<"smallFreq: "<<c<<" - "<<freqSmall[c-'a']<<endl;
    }

    while(r<big.size()){
        while(count<small.size() && r<big.size()){
            int index = big[r]-'a';
            freqBig[index]++;
            if(freqBig[index]<=freqSmall[index]){
                count++;
                cout<<"count++ to: "<<count<< " on letter: "<<r<<big[r]<< " freqBig: "<<freqBig[index]<<endl;
            }
            r++;
        }
        int current_length = r-l;
        if (current_length<min_length){
            window = {l,r-1};
            min_length = current_length;
            cout<<"window: "<<l<<","<<r-1<<endl;
        }

        int index = big[l]-'a';
        freqBig[index]--;
        if(freqBig[index]<freqSmall[index]){
            count--;
        }
        l++;
    }
    return window;
}

int main(){
    string big = "hello world";
    string small;

    getline(cin, small);

    pair<int, int> ans = smallest_window(big, small);
    cout<<ans.first<<","<<ans.second;
    return 0;
}