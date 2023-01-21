#include<bits/stdc++.h>
using namespace std;
void backtrack(string s,int ind,vector<string>& dp,vector<string> &ans){
    if(ind==s.size() && dp.size()==4){
        // collect the ans and return 
        string res;
        for(auto it:dp){ 
            if(res.empty()) res+=it;
            else res +="."+it;
        }
        ans.push_back(res);
        return;
    }
    // if the first char is 0 then take and level the rest 
    if(s[ind]=='0'){
        string temp; 
        temp.push_back(s[ind]);
        dp.push_back(temp);
        backtrack(s,ind+1,dp,ans);
        dp.pop_back();
        return;
    }
    // if 1st char is not 0 then loop through every char and make
    // the chioce to take or not 

    int temp1 = s.size()-ind;
    string num;
    for (int i = ind; i < min(3+ind,temp1+ind); i++){
        num+=s[i];
        if(stoi(num)<=255 && stoi(num)>0 && dp.size()<4){
            dp.push_back(num);
            backtrack(s,i+1,dp,ans);
            dp.pop_back();
        }
        else return;
    }
    
}
void restoreIpAddresses(string s) {
    vector<string> dp,ans;
    backtrack(s,0,dp,ans);
    for(auto it:ans) cout<<it<<"\n";
}
int main(){
 string s ="101023";
 restoreIpAddresses(s);
}