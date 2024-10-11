#include<vector>
#include<set>
#include<climits>
#include<iostream>
using namespace std;

class triplet{
    public:
        int x;
    int y;
    int dist;
    
    triplet(int d, int nx, int ny){
        dist = d;
        x = nx;
        y = ny;
    }
    // bool operator<(const triplet b) const{
    //     return this->dist<b.dist;
    // }
};

class Compare{
public:
    bool operator()(const triplet a, const triplet b) const{
        if(a.dist!=b.dist){
            return a.dist<b.dist;
        }
        // return a.x<=b.x && a.y <= b.y;
        return a.dist<b.dist;
    }
};

int dfs(vector<vector<int>> grid){
    
    set<triplet,Compare> set;      //dist, node
    
    set.insert({grid[0][0], 0,0});

    int n = grid.size(), m = grid[0].size();
    int pathdist[n][m];
    for(int a=0;a<n;a++){
        for(int b=0;b<m;b++){
            pathdist[a][b] = INT_MAX;
        }
    }
    pathdist[0][0] = grid[0][0];
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, +1, -1};
         
    while(!set.empty()){
        triplet t = *set.begin();
        
        
        //can also be pathdist[i][j] but not a redundant element in set because, thats how we sort the set
        int current_dist = t.dist; 
        cout<<"around "<<t.x<<','<<t.y<<" current distance: "<<current_dist<<endl;
        for(int k =0;k<4;k++){
            int nx = t.x +dx[k];
            int ny = t.y +dy[k];
            
            if(nx<0 || ny<0 || nx==n || ny == m){
                continue;
            }
            if(current_dist+grid[nx][ny] < pathdist[nx][ny]){
                cout<<"at "<<nx<<','<<ny<<" path dist: "<<pathdist[nx][ny]<<endl;
                triplet nt(pathdist[nx][ny], nx, ny);
                if(set.find(nt)!=set.end()){
                    set.erase(set.find(nt));        //bug same value of distance with different coordinates is replaced
                }
                
                pathdist[nx][ny] = current_dist+grid[nx][ny];
                nt.dist = pathdist[nx][ny];
                cout<<nt.dist<<endl;

                set.insert(nt);
            }
        }
        set.erase(set.find(t));
        for(auto x : set){
            cout<<x.dist<<',';
        }
        cout<<" -- set"<<endl;
    }
    return pathdist[n-1][m-1];
}

int shortest_path(vector<vector<int> > grid){
    //return the shortest path len
    
    
    
    
    int result = dfs(grid);
    
    return result;
    
    
}

int main(){
    vector<vector<int>> v = {
                            {31, 100, 64, 12,  18},
                            {10,  13,  47, 157, 6},
                            {100, 113, 174, 11, 33},
                            {88,  124, 41,  20, 140},
                            {99,  32,  111, 41, 20}
                        };
    cout<<shortest_path(v)<<" -- result" <<endl;
    return 0;
}