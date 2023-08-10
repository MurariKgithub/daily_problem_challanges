class Solution {
public:
    int FindPevertI(vector<int>& nums){
        int s = 0,e = nums.size()-1;
        while(s<=e){
            int mid = (s+e)/2;
            // if(s==e)  return mid;
            // if(mid==0 and nums[mid]<=nums[mid+1])  return mid;
            if(e>mid and nums[mid]>nums[mid+1])  return mid+1;
            else if(s<mid and nums[mid-1]>nums[mid])  return mid;
            
            else if(nums[mid]>nums[e])  s = mid+1;
            else e = mid-1;
        }
        return -1; 
    }
    int FindPevertII(vector<int>& nums){
        int s = 0,e = nums.size()-1;
        while(s<=e){
            int mid = (s+e)/2;
            // if(s==e)  return mid;
            cout<<mid<<" ";
            if(e>mid and nums[mid]>nums[mid+1])  return mid+1;
            else if(s<mid and nums[mid-1]>nums[mid])  return mid;
            
            else if(nums[mid]>=nums[e])  s = mid+1;
            else e = mid-1;
        }
        cout<<endl;
        return -1; 
    }
    int BinarySearch(int s,int e,int tg,vector<int>& nums){
        int mid,n = nums.size();
        while(s<=e){
            mid = (s+e)/2;
            if(nums[mid]==tg)   return true;
            else if(nums[mid]<tg)   s = mid+1;
            else e = mid-1;
        }
        return false;
    }
    bool search(vector<int>& arr, int target) {
        int n=arr.size(), s =0,e = n-1,mid;
        while(s<=e){
            mid = s+(e-s)/2;
            if(arr[mid]==target)   return true;
            if(arr[mid]==arr[s] and arr[mid]==arr[e]){ 
                // if(arr[mid)
                s++,e--;
            }
            
            else if(arr[mid]<arr[s]){
                if(arr[mid]<target and arr[e]>=target) s = mid+1;
                else e = mid-1;
            }
            else{
                if(arr[mid]>target and arr[s]<=target) e = mid-1;
                else s = mid+1;
            }
        }
        return false;
    }
};
