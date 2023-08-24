class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int MaxWidth) {
        int n = words.size(),ActualWidth=0;
    vector<string> collect,sent;
    for(int i=0 ;i<n ;i++){
        int m = words[i].size(),Space = collect.size();
        // cout<<words[i]<<endl;
        if(ActualWidth+Space+m<=MaxWidth){
            ActualWidth+=m;
            collect.push_back(words[i]);
        }
        else{
            int TotalSpace  = (MaxWidth - ActualWidth),extraSpace = 0,SpaceBetw=0;
            if(Space>1) SpaceBetw=TotalSpace/(Space-1),extraSpace = TotalSpace%(Space-1);
            string res;
            // cout<<TotalSpace<<" "<<MaxWidth<<" "<<ActualWidth<<" "<<extraSpace<<endl;
            int s =0;
            for(int k=0 ;k<collect.size() ;k++){
                res+=collect[k];
                for(int j=0 ;j<SpaceBetw && k<Space-1;j++){
                    if(TotalSpace==s)  break;
                    res+=" ";
                    if(extraSpace) res+=" ",extraSpace--,s++;
                    s++;
                }
            }
            while (TotalSpace>s)    res+=" ",s++;
            collect.clear();
            ActualWidth = 0;
            i--;
            // cout<<res<<" "<<i<<endl;
            sent.push_back(res);
        }
    }
    if(collect.size()){
        
        int TotalSpace  = (MaxWidth - ActualWidth) ;
            string res;
            int s =0;
            // cout<<TotalSpace<<" "<<MaxWidth<<" "<<ActualWidth<<endl;
            for(int k=0 ;k<collect.size() ;k++){
                res+=collect[k];
                if(TotalSpace>s) {
                    res+=" ";
                    s++;
                }
            }
            while (TotalSpace>s)    res+=" ",s++;
            collect.clear();
            ActualWidth = 0;
            // cout<<res<<" "<<9 <<endl;
         sent.push_back(res);
        }
        return sent;
    }
};
