class Solution{
public:
    int maxInstance(string s){
        map<char,int> frq,actual;
        string ans = "balloon";
        for(auto it:ans) actual[it]++;
        for(auto it:s) frq[it]++;
        
        int res =INT_MAX;
        for(auto it:actual){
            res =min(res,frq[it.first]/actual[it.first]);
        }
        return res;
        
    }
};
