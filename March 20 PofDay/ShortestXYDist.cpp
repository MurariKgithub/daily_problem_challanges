#include<bits/stdc++.h>
using namespace std;

// int shortestXYDist(vector<vector<char>> grid, int n, int m) {
//     vector<pair<int,int>> vis;
//     for(int i=0 ;i<n ;i++){
//         for(int j=0 ;j<m ;j++){
//            if('Y'==grid[i][j]) vis.push_back({i,j}); 
//         }
//     }
//     sort(vis.begin(),vis.end());
//     queue<pair<int,int>> q;
//     for(int i=0 ;i<n ;i++){
//         for(int j=0 ;j<m ;j++){
//            if('X'==grid[i][j]) q.push({i,j});
//         }
//     }
//     int mini = INT_MAX;
//     while(!q.empty()){
//         int x = q.front().first,y=q.front().second;
//         q.pop();
//         // cout<<node<<endl;
//         for(int i=0;i<vis.size() ;i++){
//             mini = min(mini, abs(vis[i].first-x)+abs(vis[i].second-y));
//         }
//     }
//     cout<<mini<<endl;

// }
int shortestXYDist(vector<vector<char>> grid, int n, int m) {
    vector<vector<int>> vis(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>> q;
    for(int i=0 ;i<n ;i++){
        for(int j=0 ;j<m ;j++){
            if(grid[i][j]=='X'){
                vis[i][j]=1;
                q.push({{i,j},0});
            }
        }
    }
    int ans =0;
    vector<vector<int>> del = {{0,1},{1,0},{-1,0},{0,-1}};
    while(!q.empty()){
        int x = q.front().first.first,y = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        for(int i=0 ;i<4 ;i++){
            int nx =del[i][0]+x, ny = del[i][1]+y;
            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if(grid[nx][ny]=='Y'){
                
                return dist+1;
            }
            if(!vis[nx][ny]){
                q.push({{nx,ny},dist+1});
                vis[nx][ny]=1;
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    vector<vector<char>> grid  = {{'X','O','O','O'},
                                  {'O','Y','O','Y'},
                                  {'X','X','O','O'},
                                 {'O','Y','O','O'}};
    int m =4,n=4;
    cout<<"Hello"<<endl;
    cout<<shortestXYDist(grid,n,m);

}