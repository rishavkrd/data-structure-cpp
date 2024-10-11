#include<iostream>
#include<vector>

using namespace std;

int max_selling_price (vector<int> price){
    vector<int> dp(price.size()+1,0);
    for(int length=1;length<=price.size(); length++){
        dp[length] = price[length-1];
        for(int i=1;i<length;i++){
            int shorter_length = dp[length-i] + price[i-1];
            dp[length] = max(shorter_length, dp[length]);
        }
    }
    return dp[price.size()];
}

int main(){
    vector<int> price = {1,5,8,9,10,17,17,20};
    cout<<"Max price: "<<max_selling_price(price);
    return 0;
}