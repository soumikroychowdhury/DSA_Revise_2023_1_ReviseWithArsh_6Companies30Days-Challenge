class Solution {
    const int mod=1e9+7;
    int solve(long long a,long long b){
        if(b==0) return 1;
        long long p=solve(a,b/2);
        p=(p*p)%mod;
        return b%2?(p*(a%mod))%mod:p;
    }
public:
    int minNonZeroProduct(int p) {
        long long count=(1LL<<p)-1;
        return count%mod*solve(count-1,count/2)%mod;
    }
};