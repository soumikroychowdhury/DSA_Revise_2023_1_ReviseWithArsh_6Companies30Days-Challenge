class Solution {
    const int mod=1e9+7;
    int solve(int index,vector<int> &nums,int mask,int pre,vector<vector<int>> &dp){
        if(index==nums.size()) return 1;
        if(dp[pre+1][mask]!=-1) return dp[pre+1][mask];
        int total=0;
        for(int i=0;i<nums.size();i++){
            if(mask&(1<<i)) continue;
            if(pre==-1||nums[pre]%nums[i]==0||nums[i]%nums[pre]==0){
                total=(total+solve(index+1,nums,mask|(1<<i),i,dp))%mod;
            }
        }
        return dp[pre+1][mask]=total;
    }
public:
    int specialPerm(vector<int>& nums) {
        vector<vector<int>> dp(20,vector<int>((1<<14)+1,-1));
        return solve(0,nums,0,-1,dp);
    }
};