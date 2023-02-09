class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int n = ideas.size();
    unordered_set<string> all;
    long long count=0;
    for(auto i: ideas) all.insert(i);
    vector<vector<long long>> cnt(26,vector<long long>(26,0));
    
    for(int j=0 ;j<n ;j++){
        char start = ideas[j][0];
        string left = ideas[j].substr(1);
        
        for(char i='a' ;i<='z' ;i++){
            if(i==start) continue;
            
            string x;
            x +=i;
            x +=left;
            if(all.find(x) ==all.end()) cnt[start-'a'][i-'a']++;
            
        }
    }
    // for(int i=0 ;i<4 ;i++){
    //     for(int j=0 ;j<4 ;j++)
    //      cout<<cnt[i][j]<<" ";
    //     cout<<endl;
    // }
    for(auto ch:ideas){
        // cout<<ch<<"------------------->"<<endl;
        for(char i='a' ;i<='z' ;i++){
            string x;
            x+=i;
            x+=ch.substr(1);
            if(all.find(x)==all.end()){
                count+=cnt[i-'a'][ch[0]-'a'];
            }
        }
    }
        return count;
    }
};
