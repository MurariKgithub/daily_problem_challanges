class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i=0 ;i<nums.size() ;i++){
            string res = to_string(nums[i]);
            for(auto it:res) ans.push_back(it-'0');
        }
        return ans;
    }
};
