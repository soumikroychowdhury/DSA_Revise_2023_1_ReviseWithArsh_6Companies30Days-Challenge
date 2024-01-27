class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                bool check=1;
                if(i>=2){
                    for(int k=0;k<i-1;k++) {if(nums[k]>=nums[k+1]) {check=0;break;}}
                }
                if(check&&j<n-2){
                    for(int k=j+1;k<n-1;k++) {if(nums[k]>=nums[k+1]) {check=0;break;}}
                }
                if(check&&i>0&&j<n-1){
                    if(nums[i-1]>=nums[j+1]) check=0;
                }
                ans+=check;
            }
        }
        return ans;
    }
};