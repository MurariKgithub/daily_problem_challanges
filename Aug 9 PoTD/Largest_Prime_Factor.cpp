class Solution{
private:
    using ll = long long int;
    ll PrimeNum(int n){
        int prev=1;
        for(int i=2 ;i*i<=n ;i++){
            while(n%i==0){
                prev = max(prev,i);
                n/=i;
            }
        }
        return max(prev,n);
    }
public: 
    long long int largestPrimeFactor(int N){
        // code here
        return PrimeNum(N);
    }
};
