class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size(),mx=0,index=-1;
        vector<int> count(n),pre(n);
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            count[i]=1,pre[i]=-1;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(count[i]<count[j]+1){
                        count[i]=count[j]+1;
                        pre[i]=j;
                    }
                }
            }
            if(count[i]>mx){
                mx=count[i];
                index=i;
            }
        }
        while(index!=-1){
            ans.emplace_back(nums[index]);
            index=pre[index];
        }
        return ans;
    }
};