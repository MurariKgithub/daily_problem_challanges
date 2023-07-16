// brute force way T.C = O(2**len(people)*len(people)*len(requirement)) ->TLE solution
//  
class Solution {
public:
    vector<int> ans;
    vector<vector<int>> dp;
    
    int isValid(int mask,vector<vector<string>> &arr, vector<string>& req){
        int n = arr.size(),m = req.size(),cnt=0;
        unordered_map<string,int> mp;
        vector<int> temp;
        for(int i=0;i<n ;i++){
            if(mask&(1<<i))
            {
                for(auto it:arr[i]) mp[it]++;
                cnt++;
                temp.push_back(i);
            }
        }
        for(int i=0;i<m ;i++){
            if(mp.find(req[i])== mp.end())  return 0;
        }
        if(ans.empty() or ans.size()>temp.size()) ans = temp;
        return cnt;
    }
    int func(int idx,int mask,vector<string>& req,vector<vector<string>> arr){
        int n=arr.size();
        if(n<=idx){
            int mini = isValid(mask,arr,req);
            if(mini>0)  return mini;
            return INT_MAX;
        }
        
        
        return min(func(idx+1,mask|(1<<idx),req,arr),func(idx+1,mask,req,arr));
    }
    vector<int> smallestSufficientTeam(vector<string>& req, vector<vector<string>>& arr) 
    {
        int n = arr.size();
        int mask = (1<<n)+1; 
         dp.resize(n,vector<int>(mask,-1));
         func(0,0,req,arr);
         return ans;
    }
};
// Optimal Solution using dp and memorization O(N*2**len(people))
class Solution {
public:
    vector<int> ans;
    vector<vector<int>> dp;
    vector<vector<int>> choices;
    
     int func(int idx,int mask1,vector<string>& req,vector<int>& arr){
        int n=arr.size();
        int NoOfSkills = req.size();
        if(n<=idx){
            if(mask1==(1<<NoOfSkills)-1){
                return 0;
            }  
            return 1000000;
        }
        if(dp[idx][mask1]!=-1)  return dp[idx][mask1];
        
        int pick = func(idx+1,mask1|arr[idx],req,arr)+1;
        
        
        int unpick = func(idx+1,mask1,req,arr);
         
        if(pick<unpick){
            choices[idx][mask1] = 1;
        }
         
        return dp[idx][mask1] = min(unpick,pick);
    }
    vector<int> smallestSufficientTeam(vector<string>& req, vector<vector<string>>& people) 
    {
        int n = people.size();
        dp.resize(n+1,vector<int>((1<<req.size()),-1));
        choices.resize(n+1,vector<int>((1<<req.size()),0));
        vector<int> arr(n,0),temp;
        unordered_map<string,int> mp;
        for(auto i=0 ;i<req.size() ;i++) mp[req[i]] = i;
        
        for(int i=0 ;i<n ;i++){
            int mask =0;
            for(auto it:people[i]) mask|=(1<<mp[it]);
            arr[i] = mask;
        }
        cout<<func(0,0,req,arr);
        int mask =0;
        int req_mask = (1<<req.size())-1;
        for(auto i=0 ;i<n ;i++){
            if(choices[i][mask]) {
                mask|=arr[i];
                ans.push_back(i);
            }
            if(mask==req_mask)  break;
        }
        
        return ans;
    }
};
