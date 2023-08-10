vector<vector<int>> dp;
    //Function to find the length of longest common subsequence in two strings.
    
    int lcs(int n, int m, string s1, string s2)
    {
        dp.resize(n+1,vector<int>(m+1,0));
        for(int i=n-1 ;i>=0 ;i--){
            for(int j=m-1 ; j>=0; j--){
                
                if(s1[i]==s2[j])  dp[i][j] = 1+dp[i+1][j+1];
                else dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }            
        }
        return dp[0][0];
    }
