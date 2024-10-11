#include<iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int> > &matrix, vector<vector<bool> > &visited, int i,int j,int m,int n){

	visited[i][j] = true;

	int cs = 1; 

	int dx[] = {1,-1,0,0};
	int dy[] = {0,0,1,-1};

	for(int k=0;k<4;k++){
		int nx = i + dx[k];
		int ny = j  + dy[k];

		if(nx>=0 and nx<m and ny>=0 and ny<n and matrix[nx][ny]==1 and !visited[nx][ny]){
			int subcomponent = dfs(matrix,visited,nx,ny,m,n);
			cs += subcomponent;
		}
	}
	return cs;
}


int largest_island(vector<vector<int> > matrix){
    //return the size of largest island in grid
    int m = matrix.size();
    int n = matrix[0].size();

    //visited matrix
    vector<vector<bool> > visited(m, vector<bool>(n,false));

    int largest = 0;

    for(int i=0;i<m;i++){
    	for(int j=0;j<n;j++){
    		if(!visited[i][j] and matrix[i][j]==1){

    			int size = dfs(matrix,visited,i,j,m,n);
    			if(size>largest){
    				largest = size;
    			}

    		}

    	}
    }    
    return largest;
}

int dfs2(vector<vector<int>> grid, int i, int j, vector<vector<bool>> &visited){
    if(i<0 || j<0 || i==grid.size() || j == grid[0].size() || visited[i][j] || grid[i][j]==0){
        return 0;
    }

    visited[i][j] = true;

    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};

    int largest=0;

    for(int k=0;k<4;k++){
        int nx = i + dx[k];
        int ny = j + dy[k];

        largest = max(largest, 1 + dfs2(grid, nx, ny, visited));

    }
    return largest;
}
int largest_island2 (vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> visited(n,vector<bool>(m, false));

    int largest =0;

    for(int i=0;i<n;i++){
        for(int j =0; j<m;j++){
            largest = max(largest,dfs2(grid, i, j, visited));
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
    
    cout<< largest_island2(grid) <<endl;


    return 0;
}
