class Solution {
    const int mod=1e9+7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int ans=0;
        long long cur=0;
        vector<long long> dp(n);
        dp[0]=1;
        for(int i=1;i<n;i++){
            long long a=0,b=0;
            if(i-delay>=0) a=dp[i-delay];
            if(i-forget>=0) b=dp[i-forget];
            cur+=(a-b+mod)%mod;
            dp[i]=cur;
        }
        for(int i=n-forget;i<n;i++) ans=(ans+dp[i])%mod;
        return ans;
    }
};