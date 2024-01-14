class Solution {
    const int mod=1e9+7;
    long long im(long long a){
        if(a==1) return 1;
        return (mod-mod/a)*im(mod%a)%mod;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        if((startPos-endPos-k)&1||abs(startPos-endPos)>k) return 0;
        long long ans=1;
        for(int i=0;i<(endPos-startPos+k)/2;i++){
            ans=(ans*(k-i))%mod;
            ans=(ans*im(i+1))%mod;
        }
        return ans;
    }
};