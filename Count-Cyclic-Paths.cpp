// Brute force Recursion + Memorization Top-down approch 
class Solution{ 
private:
    int mod = 1e9+7;
    map<char,vector<char>> mp;
    vector<vector<int>> dp,adjls = {{1,2,3},{2,3,0},{1,3,0},{1,2,0}};
    
    ll func(int n,char cur){
        if(n==0){
            if(cur=='O') return 1;
            return 0;
        }
        int ch = (cur=='O')?3:cur-'A';
        if(dp[ch][n]!=-1) return dp[ch][n];
        ll ans=0;
        for(auto it:mp[cur]){
            ans = (ans +func(n-1,it))%mod;
        }
        return dp[ch][n] = ans;
    }
public:
    int countPaths(int n){
        dp.resize(n+1,vector<int>(4,-1));
        mp['O'] = {'A','B','C'};
        mp['A'] = {'B','C','O'};
        mp['B'] = {'A','C','O'};
        mp['C'] = {'A','B','O'};
        return func(n,'O');
    }
// Bottom-Up approch TC = O(N*16) and S.C = O(1) TLE solution still
class Solutions{
public:
 vector<vector<int>> dp,adjls = {{1,2,3},{2,3,0},{1,3,0},{1,2,0}};
 int countPaths(int n){
   vector<int> dp1(4,0),dp2(4,0);
        dp1[0]= 1;
        for(int i=1; i<=n;i++){
            for(int cur=0 ;cur<4 ;cur++){
                ll ans =0;
                for(auto it:adjls[cur]) ans = (ans+dp1[it])%mod;
                dp2[cur] = ans;
            }
            dp1 = dp2;
        }
        return dp1[0];
     }
}
class Solutions{
public:
 vector<vector<int>> dp,adjls = {{1,2,3},{2,3,0},{1,3,0},{1,2,0}};
 int countPaths(int n){
   vector<int> dp1(4,0),dp2(4,0);
        dp1[0]= 1;
        for(int i=1 ;i<=n ;i++){
            dp2[0] = ((dp1[1]+dp1[2])%mod+dp1[3])%mod;
            dp2[1] = ((dp1[0]+dp1[2])%mod+dp1[3])%mod;
            dp2[2] = ((dp1[1]+dp1[3])%mod+dp1[0])%mod;
            dp2[3] = ((dp1[1]+dp1[0])%mod+dp1[2])%mod;
            dp1 = dp2; 
        }
        return dp1[0];
     }
}
