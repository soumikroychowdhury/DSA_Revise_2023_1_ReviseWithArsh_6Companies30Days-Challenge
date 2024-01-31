class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans=0,i=0,j=0;
        unordered_map<int,int> m;
        for(i=0;i<nums.size();i++){
            m[nums[i]]++;
            if(m[nums[i]]>k){
                while(i>=j&&m[nums[i]]>k){
                    m[nums[j]]--;
                    j++;
                }
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};