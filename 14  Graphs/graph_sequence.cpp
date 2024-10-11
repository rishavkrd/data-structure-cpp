#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int dfs(vector<vector<int>> grid, vector<vector<bool>> &visited, vector<vector<int>> &dp, int i, int j){
	// if(i<0 || j<0 || i==grid.size() || j == grid[0].size() ){
	// 	return 0;
	// }
	if(visited[i][j]) return dp[i][j];
	visited[i][j] = true;

	int dx[] = {1,-1,0,0};
	int dy[] = {0,0,-1,1};

	int longest=1;

	for(int k =0;k<4;k++){
		int nx = dx[k] + i;
		int ny = dy[k] + j;
		if(nx<0 || ny<0 || nx==grid.size() || ny == grid[0].size() ){
			continue;
		}
		if(grid[nx][ny]>grid[i][j]){
			int l = 1 + dfs(grid, visited, dp, nx, ny);
			if(l>longest){
				longest = l;
			}
		}
	}
	dp[i][j] = longest;
	return longest;

}

int main(){
	vector<vector<int> > grid = {
								  {0,  2,  4,  3,  2},
								  {7,  6,  5,  5,  1},
								  {8,  9,  7, 18, 14},
								  {5, 10, 11, 12, 13},
								};
	int n = grid.size(), m = grid[0].size();
	vector<vector<bool>> visited(n, vector<bool>(m,false));
	vector<vector<int>> dp(n, vector<int>(m,0));
	int longest =0;
	for(int i=0;i<n;i++){
		for(int j= 0;j<m;j++){
			if(!visited[i][j]){
				int l = dfs(grid, visited, dp, i, j);
				if(longest<l){
					longest = l;
				}
			}
		}
	}

	cout<<longest<<endl;
	return 0;
}