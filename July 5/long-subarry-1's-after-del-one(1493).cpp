class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int sum=0,cnt=0,n = nums.size(),l=0;
        for(int i=0 ;i<n ;i++){
            sum+=(nums[i]==0?-1:nums[i]);
            while(l<i and sum<i-l-1){
                sum+=(nums[l]==0?1:-1);
                l++;
            }
            cnt = max(cnt,i-l);
        }
        return cnt;
    }
};
