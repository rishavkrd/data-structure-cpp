#include<iostream>
#include<vector>
#include<set>

using namespace std;

int shortest_path(vector<vector<int>> v){
    int n = v.size();
    int m = v[0].size();

    vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(m, INT_MAX));
    set<pair<int,pair<int,int>>> s;
    s.insert({v[0][0],{0,0}});

    while(!s.empty()){
        auto front = s.begin();
        pair<int,int> coord = front->second;
        int currentDistance = front->first;
        s.erase(front);
        
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        for(int i=0;i<4;i++){
            int x = coord.first + dx[i];
            int y = coord.second + dy[i];

            if(x<0 || y<0 || x>=n || y>=m){
                continue;
            } else {
                
                int distance = currentDistance + v[x][y];
                if(distance<=dp[x][y]){
                    dp[x][y] = distance;
                    if(s.find({dp[x][y], {x,y}})!=s.end()){
                        s.erase({dp[x][y], {x,y}});
                    }
                    s.insert({distance, {x,y}});
                }
            }
        }
    }
    return dp[n-1][m-1];
}

int main(){
    vector<vector<int>> v = {
                            {31, 100, 65, 12,  18},
                            {10,  13,  47, 157, 6},
                            {100, 113, 174, 11, 33},
                            {88,  124, 41,  20, 140},
                            {99,  32,  111, 41, 20}
                        };
    

    cout<<shortest_path(v)<<" -- result" <<endl;
    return 0;
}