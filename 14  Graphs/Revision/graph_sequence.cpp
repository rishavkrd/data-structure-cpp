#include<iostream>
#include<vector>

using namespace std;

int dfs(vector<vector<int>> grid, int i, int j, vector<vector<int>> &dp){
    if(dp[i][j]>0) return dp[i][j];
    int n = grid.size();
    int m = grid[0].size();
    
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};

    int res = 0;

    for(int k=0; k<4; k++){
        int x = i+dx[k];
        int y = j+dy[k];

        if(x<0 || y<0 || x>=n || y>=m || grid[x][y]<=grid[i][j]){
            continue;
        }

        res = max(res, dfs(grid, x,y, dp));

    }
    cout<<endl<<"dp : "<<i<<","<<j<<" : "<<res+1;
    return dp[i][j] = res+1;
}

int largest_subsequence(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m, -1));
    int longest = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            longest = max(longest, dfs(grid, i,j, dp));
        }
    }
    return longest;
}

int dfs2(vector<vector<int>> grid, vector<vector<int>> &dp, int i, int j){
    if(dp[i][j] != 0){
        return dp[i][j];
    }
    int res = 0;

    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};

    for(int k=0; k<4;k++){
        int x = i + dx[k];
        int y = j + dy[k];
        cout<<x<<","<<y<<endl;
        if(x>=0 && y>=0 && x<grid.size() && y <grid[0].size() && grid[x][y]>grid[i][j]){
            cout<<x<<","<<y<<"->"<<grid[x][y]<<endl;
            res = max(res, dfs2(grid, dp, x, y));
        }
    }
    cout<<i<<","<<j<<" : "<<res+1<<endl;
    return dp[i][j] = res+1;
}

int largest_subsequence2(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m,0));
    int longest = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            longest = max(longest, dfs2(grid, dp, i,j));
        }
    }
    return longest;
}

int main(){
	vector<vector<int> > grid = {
								  {0,  2,  4,  3,  2},
								  {7,  6,  5,  5,  1},
								  {8,  9,  7, 18, 14},
								  {5, 10, 11, 12, 13},
								};
    //
    int ans = largest_subsequence2(grid);
    cout<<endl<<"Largest sequence: "<< ans;
    return 0;
}