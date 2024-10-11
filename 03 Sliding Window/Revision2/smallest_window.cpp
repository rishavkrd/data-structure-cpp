#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

pair<int, int> smallest_window(string s, string pattern){
        int l=0, r= 0;
        vector<int> freq_pattern(257, 0);
        for(int i=0; i<pattern.size();i++){
            freq_pattern[pattern[i]]++;
        }
        int count = pattern.size();
        int min_len = INT_MAX;
        pair<int,int> res = {-1,-1};
        if(s.size()<pattern.size()) return res;
        while(l<=r && r<=s.size()){

            while(count>0){
                if(r>=s.size()){
                    return res;
                }
                int key = s[r];
                if(freq_pattern[key]>0){
                    count--;
                }
                freq_pattern[key]--;
                r++;
            }
            if(r-l<min_len && count==0){
                res = {l,r-1};
                min_len = r-l;
            }
            int left_key = s[l];
            freq_pattern[left_key]++;
            if(freq_pattern[left_key]>0){
                count++;
            }
            l++;

        }
        return res;
    }

int main(){
    pair<int, int> res = smallest_window("hello world", "lol");
    cout<<"l,r: "<< res.first<<", "<<res.second<<endl;
    return 0;
}