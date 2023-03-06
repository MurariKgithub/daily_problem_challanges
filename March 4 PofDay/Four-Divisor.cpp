#include <bits/stdc++.h> 
int primefactor(int no){
    int k=0,sum=0;
    for(int i=1 ;i*i<=no ;i++){
        if(k>4) return 0;
        if(no%i==0){
            sum+=i;
            k++;
            if(no/i!=i){
                sum+=(no/i);
                k++;
            }
        }
    }
    return k==4?sum:0;
    
}
int sumFourDivisors(vector<int> &arr, int n)
{   int ans =0;
    for(int i=0 ;i<n ;i++){
        int val = primefactor(arr[i]);
        // cout<<val<<" "<<arr[i]<<endl;
        ans+=val;
    }
    return ans;
}
