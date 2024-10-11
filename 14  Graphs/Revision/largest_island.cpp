#include<iostream>
#include<vector>

using namespace std;

int dfs(vector<vector<int>> &grid, int i, int j){
    if(grid[i][j]==0){
        return 0;
    }
    grid[i][j] = 0;

    int n = grid.size();
    int m = grid[0].size();
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};

    int res = 0;

    for(int k =0; k<4;k++){
        int x = i + dx[k];
        int y = j + dy[k];
        if(x<0 || y<0 || x>=n || y>=m || grid[x][y]==0){
            continue;
        }
        res += dfs(grid, x,y);
    }
    return 1+res;
}

int largest_island(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();

    int largest = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            largest = max(largest, dfs(grid, i, j));
        }
    }
    return largest;
}

int main(){
    vector<vector<int> > grid = {
                            {1, 0, 0, 1, 0},
                            {1, 0, 1, 0, 0},
                            {0, 0, 1, 0, 1},
                            {1, 0, 1, 1, 1},
                            {1, 0, 1, 1, 0}
                            };
    
    cout<<"Largest Island: "<< largest_island(grid) <<endl;


    return 0;
}