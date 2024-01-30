class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        map<int,vector<int>> m;
        priority_queue<int> q;
        for(int i=0;i<nums.size();i++) m[nums[i]].push_back(i);
        for(int &num:nums) q.push(num);
        while(k--){
            int a=q.top();
            q.pop();
            ans.emplace_back(m[a].back());
            m[a].pop_back();
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++) ans[i]=nums[ans[i]];
        return ans;
    }
};