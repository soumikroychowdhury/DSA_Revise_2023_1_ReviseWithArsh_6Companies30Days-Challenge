class Solution {
    const int mod=1e9+7;
    vector<int> primes={2,3,5,7,11,13,17,19,23,29};
    long long getMask(long long num){
        long long mask=0;
        for(int i=0;i<10;i++){
            int tim=0;
            while(num%primes[i]==0){
                tim++;
                num/=primes[i];
            }
            if(tim>1) return -1;
            if(tim==1) mask|=(1<<(i+1));
        }
        return mask;
    }
    long long dfs(int index,long long p,vector<int> &nums,vector<vector<long long>> &dp){
        if(index>=nums.size()) return 0;
        if(dp[index][p]!=-1) return dp[index][p];
        long long mask=getMask(nums[index]);
        long long ans=dfs(index+1,p,nums,dp);
        if((p&mask)==0) ans=(++ans+dfs(index+1,p|mask,nums,dp))%mod;
        return dp[index][p]=ans;
    }
public:
    int squareFreeSubsets(vector<int>& nums) {
        vector<vector<long long>> dp(1111,vector<long long>(1<<11,-1));
        return dfs(0,1,nums,dp)%mod;
    }
};