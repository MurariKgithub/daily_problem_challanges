class Solution {
  public:
  vector<int> arr;
  vector<vector<int>> dp;
    int func(int idx,bool flag){
        if(idx==arr.size())  return 0;
        if(dp[idx][flag]!=-1)  return dp[idx][flag];
        int pick = 0,unpick=0;
        if(flag){
            pick = max(-arr[idx]+func(idx+1,false),func(idx+1,flag));
        }
        else unpick = max(arr[idx]+func(idx+1,true),func(idx+1,flag));
        return dp[idx][flag] = max(pick,unpick);
    }
    int stockBuyAndSell(int n, vector<int> &prices) {
        this->arr = prices;
        dp.resize(n+1,vector<int>(2,-1));
        return func(0,true);
    }
};
