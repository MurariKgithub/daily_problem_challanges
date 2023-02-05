class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int cnt=0,cursum=0;
        map<int,int> mp;
        for(auto it:banned) mp[it]+=1;
        
        for(int i = 1 ;i<=n ;i++){
            if(mp[i]) continue;
            
            if(maxSum>=i+cursum){ 
                cursum+=i,cnt++;
            }
            else return cnt;
            
        }
        return cnt;
    }
};
