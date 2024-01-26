class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=0,sum=0;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++) nums[i]%=2;
        m[0]++;
        for(int &num:nums){
            sum+=num;
            if(m.find(sum-k)!=m.end()) ans+=m[sum-k];
            m[sum]++;
        }
        return ans;
    }
};