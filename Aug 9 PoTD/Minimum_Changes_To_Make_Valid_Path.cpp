#include <bits/stdc++.h> 
map<char,pair<int,int>> mp;
vector<vector<int>> del = {{-1,0},{1,0},{0,-1},{0,1}};


// int dfs(int i,int j ,vector<vector<char>> &mat,vector<vector<int>> &vis){
// 	int n = mat.size(),m = mat[0].size();
// 	if(i>=n or j>=m or j<0 or i<0 or vis[i][j])   return INT_MAX;
// 	if(i==n-1 and j==m-1)  return 0;

//     // cout<<i<<" "<<j<<endl;
// 	int curmin = INT_MAX;
// 	vis[i][j] = 1;
// 	for(int k= 0; k<4 ;k++){
// 		int x = i+del[k][0], y =del[k][1]+j;
// 		int val = dfs(x,y,mat,vis);
// 		if(val!=INT_MAX){
//             pair<int,int> temp =  {del[k][0],del[k][1]};
// 			if(mp[mat[i][j]]==temp){  
//                 curmin = min(val,curmin);
                
//             }
// 			else curmin = min(val+1,curmin);
//             // cout<<val<<" "<<i<<" "<<j<<endl;
// 		}
// 	}
//     vis[i][j] =0;
// 	return curmin;
// }
int bfs(int i, int j, vector<vector<char>> &mat) {
    int curmin = INT_MAX;
    int n = mat.size(),m = mat[0].size();
    vector<vector<int>> vis(n+1,vector<int>(m+1,INT_MAX));
    vis[i][j] = 0;
    priority_queue<pair<int,pair<int,int>>> q;
    q.push({0,{0,0}});

    while(!q.empty()){
        int cost = -q.top().first,x = q.top().second.first,y = q.top().second.second;
        q.pop();
        
        // cout<<x<<","<<y<<"->\n" ;
        for(int k= 0; k<4 ;k++){
		    int nx = x+del[k][0], ny =del[k][1]+y;
	    	if(nx>=n or ny>=m or ny<0 or nx<0)   continue;
	        
		    
            pair<int,int> temp =  {del[k][0],del[k][1]};
			if(mp[mat[x][y]]==temp){  
                if(vis[nx][ny]>cost){
                    // cout<<nx<<" "<<ny<<" "<<cost<<endl;
                     q.push({-cost,{nx,ny}}); 
                     vis[nx][ny] = cost;
                }
            }
			else{ 
                if(vis[nx][ny]>cost+1){
                    // cout<<nx<<" "<<ny<<" "<<cost<<endl;
                     q.push({-cost-1,{nx,ny}}); 
                     vis[nx][ny] = cost+1;
                }
            }
	    }
    }
    return vis[n-1][m-1];

}
int minChanges(int n, int m, vector<vector<char>> &matrix){
	// Write your code here.
	mp['U'] = {-1,0},mp['D'] = {1,0},mp['R'] = {0,1},mp['L'] = {0,-1};

	
	return bfs(0,0,matrix);
}
