#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

int main(){
    string inp;
    getline(cin, inp);

    unordered_set<char> set;

    int l=0, r=0, count=0, ans=0;

    while(r<inp.size()){
        while(set.find(inp[r]) != set.end()){
            set.erase(inp[l]);
            l++;
            count--;
        }
        set.insert(inp[r]);
        count++;
        r++;
        ans = max(count, ans);
    }
    cout<<"longest unique string: "<<ans;
    return 0;
}