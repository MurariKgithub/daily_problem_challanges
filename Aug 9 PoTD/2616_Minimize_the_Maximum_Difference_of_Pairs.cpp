class Solution {
public:
    int isPossible(int p,int mid,vector<int>& nums){
        int n = nums.size(),i=1,k=0;
        
        while(i<n){
            if(nums[i] - nums[i-1] <= mid){
                k++;
                i++;
            }
            i++;
        }
        
        return k>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n= nums.size(),s =0,e = nums[n-1]-nums[0];
        
        while(s<=e){
            int mid = (s+e)/2;
            if(!isPossible(p,mid,nums))  s = mid+1;
            else e = mid-1;
        }
        
        return s;
    }
};
