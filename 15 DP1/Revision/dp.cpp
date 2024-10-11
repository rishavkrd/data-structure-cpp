#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int kladder(int n, int k){
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;

    for(int i=2;i<=n;i++){
        for(int j=i-1; j>=0 && j>=i-k; j--){
            dp[i] += dp[j];
        }
    }
    return dp[n];
}

int coinChange(vector<int> coins, int target){
    vector<int> dp(target+1, 0);
    for(int i=1; i<=target; i++){
        int min_coin = INT_MAX-1;
        for(int c : coins){
            if(i-c>=0){
                min_coin = min(min_coin, dp[i-c]);
            }
        }
        dp[i] = min_coin +1;
    }
    return dp[target];
}
 int coinChange2(vector<int> coins, int target){
    vector<int> dp(target+1, INT_MAX-1);
    dp[0] = 0;
    int n = coins.size();
    for(int i=1; i<=target; i++){
        for(int j=0; j<n; j++){
            if(i-coins[j]>=0){
                dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
    }
    return dp[target];
 }

int jump1(vector<int> arr){
    vector<int> dp(arr.size(), INT_MAX-1);
    dp[0] = 0;
    for(int i=1; i<arr.size(); i++){
        for(int j=0; j<arr[i-1]; j++){
            dp[i+j] = min(dp[i+j], dp[i-1]+1);
        }
    }
    return dp[arr.size()-1];
}

int jump1_2(vector<int> arr){
    vector<int> dp (arr.size(), INT_MAX-1);
    dp[0] = 0;
    for(int i=0; i<arr.size(); i++){
        for(int j=1; j<=arr[i] && i+j<arr.size(); j++){
            dp[i+j] = min(dp[i+j], dp[i]+1);
        }
    }
    return dp[arr.size()-1];
}

int max_wine_price(vector<int> arr){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n,0));
    
    for(int i=0;i<n; i++){
        dp[i][i] = (n)*arr[i];
        cout<<arr[i]<<"\t";
    }
    cout<<endl<<"Array ^ ";
    cout<<endl;

    for(int l=n-1;l>0;l--){
		for(int r=1;r<n;r++){
            if(l<r){
                int factor = l-1;
                int left = dp[l-1][r]+arr[r]*factor;
                int down = dp[l][r]+arr[l]*factor;
                cout<<l<<","<<r<<" - left, down: "<<left<<","<<down<<endl;
                dp[l][r] = max(left, down);
            }
            
        }
    }
    for(auto a : dp){
        for(auto k : a){
            cout<<k<<"\t";
        }
        cout<<endl;
    }
    return dp[0][n-1];
}

int max_wine_price2(vector<int> arr){

}

int frog_min_jump(vector<int> arr){
    int n = arr.size();
    vector<int> dp(n,INT_MAX);
    dp[0] = 0;

    for(int i=0; i<n-1; i++){
        dp[i+1] = min(dp[i+1], dp[i]+abs(arr[i]-arr[i+1]));
        if(i+2<n){
            dp[i+2] = dp[i]+abs(arr[i]-arr[i+2]);
        }
    }
    return dp[n-1];
}

int frog_min_jump2(vector<int> arr){
    int n = arr.size();
    vector<int> dp(n,INT_MAX);
    dp[0] = 0;

    for(int i=0; i<n-1; i++){
        dp[i+1] = min(dp[i+1], dp[i]+abs(arr[i]-arr[i+1]));
        if(i+2<arr.size()) dp[i+2] = min(dp[i+2], dp[i]+abs(arr[i]-arr[i+2]));
    }
    return dp[n-1];
}

int subsequenceCount(string a, string b){
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0){
                dp[i][j] = 1;
            } else if(a[j-1] == b[i-1] && dp[i-1][j-1]==1){
                dp[i][j] = dp[i][j-1] + 1;
            } else if(j!=0){
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
            }
        }
    }
    cout<<endl;
    for(auto i : dp){
        for (auto j:i){
            cout<<j<<"\t";
        }
        cout<<endl;
    }
    // int ans = 0;
    // for(int k : dp[m]){
    //     ans+=k;
    // }
    return dp[m][n];
}

int rod_cutting(vector<int> rod_prices){
    int n = rod_prices.size();
    vector<int> dp(n+1, 0);

    for(int len=1; len<=n; len++){
        dp[len] = rod_prices[len-1];
        for(int cut=1; cut<len;cut++){
            dp[len] = max(dp[len], dp[len-cut] + rod_prices[cut-1]);
        }
    }
    return dp[n];
}

int longest_increasing_subsequence(vector<int> nums){
    int n = nums.size(), max_len = 0;
        vector<int> seq;
        seq.push_back(nums[0]);
        int size = 1;
        for(int i=1; i<n; i++){
            if(nums[i]<seq[size-1]){
                int idx = lower_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
                seq[idx] = nums[i];
            }
            else if (nums[i]>seq[size-1]){
                size++;
                seq.push_back(nums[i]);
            }
        }
        return seq.size();
}

int longest_common_subsequence(string s1, string s2){
    int n1 = s1.size(), n2 = s2.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

    for(int i=1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
            } else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    for(auto i : dp){
        for(auto j : i){
            cout<<j<<"\t";
        }
        cout<<endl;
    }
    //backtrack common sequence
    vector<char> res;
    int i=n1, j=n2;
    while(i!=0 && j!=0){
        if(dp[i][j]==dp[i][j-1]){
            j--;
        } else if(dp[i][j]==dp[i-1][j]){
            i--;
        } else{
            res.push_back(s1[i-1]);
            i--; j--;
        }
    }
    reverse(res.begin(), res.end());
    for(auto c : res){
        cout<<c<<" ";
    }

    return dp[n1][n2];
}

int selling_wines(vector<int> arr){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n,0));
    for(int i=0; i<n; i++){
        dp[i][i] = arr[i]*n;
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<n-i; j++){
            int year = n-i;
            int l = j, r = j+i;
            int left = dp[l][r-1] + arr[r]*year;
            int right = dp[l+1][r] + arr[l]*year;
            dp[l][r] = max(left, right);
        }
    }

    //print dp
    for(auto i : dp){
        for(auto j : i){
            cout<<j<<"\t";
        }
        cout<<endl;
    }
    return dp[0][n-1];
    
}

int knapsack(vector<int> wts, vector<int> prices, int capacity){
    int n = wts.size();
    vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=capacity; j++){
            dp[i][j] = dp[i-1][j];
            if(j-wts[i-1]>=0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-wts[i-1]] + prices[i-1]);
            }
        }
    }
    //print dp
    for(auto i : dp){
        for(auto j : i){
            cout<<j<<"\t";
        }
        cout<<endl;
    }

    return dp[n][capacity];
}

int main(){
    // cout<<kladder(5,3);
    vector<int> coins = {1,3,7,10};
    vector<int> arr = {3,4,2,1,2,3,3,10,1,1,1,2,5};
    vector<int> wine_price = {2,3,5,1,4};
    vector<int> frog_jump = {30,10,60,10,60,50};
    vector<int> rod_prices = {1,5,8,9,10,17,17,20};
    string s1 = "ABECDGC", s2="ABCD";
    vector<int> wines = {2,3,5,1,4};
    vector<int> wts = {2,7,3,4};
    vector<int> prices = {5,20,20,10};
    cout<<"Knapsack: \n"<<knapsack(wts, prices, 11)<<endl;
    // cout<<"Selling wines: \n"<<selling_wines(wines)<<endl;
    // cout<<"longest common subsequence: \n"<<longest_common_subsequence(s1,s2)<<endl;
    // cout<<"Coins change2 : "<<coinChange2(coins, 15)<<endl;
    // cout<<"Jump1: "<<jump1_2(arr)<<endl;
    // cout<<"Rod Cutting: "<<rod_cutting(rod_prices)<<endl;
    // cout<<"Sell Wines: "<<endl<<max_wine_price2(wine_price)<<endl;
    // cout<<"Frog Min cost: "<<frog_min_jump2(frog_jump);
    // cout<<"Subsequence Count: "<<subsequenceCount("ABCDCE", "ABC");
    return 0;
}