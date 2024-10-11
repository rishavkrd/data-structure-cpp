#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> dp (100,vector<int>(100, -1));
int count=0;

int sell_wines(vector<int> prices, int l, int r, int year){
	if(l>r){
		return 0;
	}
	count++;
	if(dp[l][r]!=-1) return dp[l][r];
	int left = prices[l] * year + sell_wines(prices, l+1, r, year+1);
	int right = prices[r] * year + sell_wines(prices, l,r-1, year+1);

	return dp[l][r] = max(left, right);
}

int sell_wines_dp(vector<int> prices){
	int n = prices.size();
	vector<vector<int>> mem(n+1, vector<int>(n+1,0));
	int off = 0;
	
	for(int l=n-1;l>=0;l--){
		// int l = 0, r = off;
		
		for(int r=0;r<n;r++){
			int year = n-(r-l);
			// mem[l][r] = 0;  
			if(l<=r){
				int left = prices[l]*year + mem[l+1][r];
				int right = prices[r]*year + mem[l][r-1];
				cout<<"point: "<<l<<','<<r<<"year, left, right"<<year<<','<<left<<','<<right<<endl;
				mem[l][r] = max(left, right);
			}
		}
		// year--;
	}
	for(int i=0;i<n; i++){
		for(int j : mem[i]){
			cout<<j<<' ';
		}
		cout<<endl;
	}

	return mem[0][n-1];
}

int main(){
	vector<int> wine_price = {2,3,5,1,4};
	cout<<sell_wines(wine_price, 0, wine_price.size()-1, 1)<<endl;
	cout<<sell_wines_dp(wine_price)<<endl;
	// cout<<"calls: "<<count<<endl;
	return 0;
}