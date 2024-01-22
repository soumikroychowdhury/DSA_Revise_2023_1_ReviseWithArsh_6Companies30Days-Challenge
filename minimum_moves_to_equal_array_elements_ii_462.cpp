class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans=0,n=nums.size();
        sort(nums.begin(),nums.end());
        for(int &num:nums) ans+=abs(nums[n/2]-num);
        return ans;
    }
};