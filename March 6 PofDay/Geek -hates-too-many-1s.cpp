class Solution {

  public:
    int noConseBits(int n) {
       int mask=0,j=0;
    for(int i=0 ;i<31 ;i++){
        if((1<<i)&n){ 
            mask = 1<<i;
            j=i;
        }
    }    
    int ans =0;
    for (int i = 0; i <=j; i++)
    {   if(((mask>>i)&n)==(mask>>i)) ans++;
        // cout<<ans<<endl;
        else ans =0;
        if(ans==3){
            ans=0;
            n-=(mask>>i);
        }
    }
    return n;
    }
};
