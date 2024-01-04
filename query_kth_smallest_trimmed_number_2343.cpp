class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto &query:queries){
            vector<pair<string,int>> v;
            int k=query[0]-1,trim=query[1];
            for(int i=0;i<nums.size();i++) v.push_back({nums[i].substr(nums[i].size()-trim,trim),i});
            sort(v.begin(),v.end());
            ans.push_back(v[k].second);
        }
        return ans;
    }
};