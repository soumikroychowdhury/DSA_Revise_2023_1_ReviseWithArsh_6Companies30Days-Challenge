class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans=0,size=nums.size(),a=0,sum=0;
        for(int i=0;i<size;i++){
            a+=i*nums[i];
            sum+=nums[i];
        }
        ans=a;
        for(int i=size-1;i>=1;i--){
            a=a+sum-size*nums[i];
            ans=max(ans,a);
        }
        return ans;
    }
};