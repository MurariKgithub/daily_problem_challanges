class Solution {
public:
    int maximizeWin(vector<int>& arr, int k) {
    int l=0,n=arr.size(),res=1;
    
    vector<int> dp(n+1,0);
    for(int i=0 ;i<n ;i++){
        // if val become's greater then k then remove from left 
        
        while(l<i && arr[i]-arr[l]>k) l++;
        // else update the dp with max length so far which we computed 
        // compair present computed lenght with previous lenght (dp[i])
        // and store maximum among it 
        dp[i+1] = max(dp[i],i-l+1);
        // pick the maximum ans among all length calculated
        res = max(res,dp[l]+(i-l+1));
       
    }
     return res;
    }
};
