class Solution{
public:
    int maxInstance(string s){
        map<char,int> frq,actual;
        string ans = "balloon";
        // step1 : actual map crate with no of ballon letter requires 
        for(auto it:ans) actual[it]++;
        // step 2; create frq map 
        for(auto it:s) frq[it]++;
       
        int res =INT_MAX;
        for(auto it:actual){
            res =min(res,frq[it.first]/actual[it.first]);
        }
        return res;
        
    }
};
