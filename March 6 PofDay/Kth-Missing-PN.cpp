class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr[0]-1>=k)  return k;
        int s = 0,e = arr.size()-1,mid;
        while(s<=e){
            mid = (s+e)/2;
            if((arr[mid]-(mid+1))<k) s=mid+1;
            else e=mid-1;
        }
        
        return arr[e]+k-(arr[e]-s);
    }
};
