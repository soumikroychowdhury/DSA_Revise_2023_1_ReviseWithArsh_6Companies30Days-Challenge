class Solution {
    const int mod=1e9+7;
    int p(int n){
        int ans=1;
        long base=2;
        while(n){
            if(n&1) ans=ans*base%mod;
            base=base*base%mod;
            n>>=1;
        }
        return ans;
    }
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        vector<int> count(31);
        vector<int> primes={2,3,5,7,11,13,17,19,23,29};
        long long dp[1024]={1};
        for(int &num:nums) count[num]++;
        for(int num=2;num<=30;num++){
            if(count[num]==0||num%4==0||num%9==0||num%25==0)continue;
            int mask=0;
            for(int i=0;i<10;i++){
                if(num%primes[i]==0) mask|=(1<<i);
            }
            for(int i=0;i<1024;i++){
                if(!(i&mask)) dp[i|mask]=(dp[i|mask]+count[num]*dp[i])%mod;
            }
        }
        return reduce(dp+1,dp+1024,0LL,[&](auto sum,long long a){
            return (sum+a)%mod;
        })*p(count[1])%mod;
    }
};