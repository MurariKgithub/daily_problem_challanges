// brute force Approch 
//Time Complexity: O(N*M) S.C = O(N)
class Solution{   
public:
    int minIteration(int n, int m, int x, int y){    
        // code here
        queue<pair<pair<int,int>,int>> q;
        q.push({{x-1,y-1},0});
        int cnt =0;
        vector<vector<int>> neg = {{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[x-1][y-1] = 1;
        while(!q.empty()){
            int a = q.front().first.first,b = q.front().first.second;
            int cost = q.front().second;
            q.pop();
            // cout<<a<<" "<<b<<endl;
            for(int i=0 ;i<4 ;i++){
                int na = neg[i][0]+a,nb = neg[i][1]+b;
                if(na<n && nb<m && na>=0 && nb>=0 && vis[na][nb]==0) q.push({{na,nb},cost+1}),vis[na][nb]=1;
            }
            cnt = max(cnt,cost);
        }
        //cout<<cnt<<endl;
        return cnt;
}
};
//Time Complexity: O(1) S.C = O(1)
class Solution{   
public:
    int minIteration(int n, int m, int x, int y){ 
      int right = n-x,left = x-1;
      int top = y-1,bottom = m-y;
      return max(top+right,max(top+left,max(bottom+left,bottom+right)));
    }
}
