#include<bits/stdc++.h>
using namespace std;
void func(vector<int> &nums,int ind,set<vector<int>>& ans,vector<int> &dp){
    if(ind==nums.size()){
        if(dp.size()>1){
            vector<int> temp;
            for(auto it:dp)  temp.push_back(it);
            ans.insert(temp);
        }
        return ;
    }
    if(dp.size()==0 || nums[ind]>=dp[dp.size()-1]){
        dp.push_back(nums[ind]);
        func(nums,ind+1,ans,dp);
        dp.pop_back();
    }
    func(nums,ind+1,ans,dp);
    return;
}
void findSubsequences(vector<int>& nums) {
      set<vector<int>> ans;
      vector<int> dp;
      func(nums,0,ans,dp);
      for(auto arr:ans){
        cout<<"{";
        for(auto elem:arr) cout<<elem<<" ";
        cout<<"}"<<endl;
      }  
}
int main(){
    vector<int> nums = {4,6,7,7};
    findSubsequences(nums);
}