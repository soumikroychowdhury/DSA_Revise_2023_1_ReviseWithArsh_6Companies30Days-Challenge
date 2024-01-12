class Solution {
    void solve(vector<int> &nums,int k,int p,set<vector<int>> &s){
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            int count=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%p==0) count++;
                v.push_back(nums[j]);
                if(count<=k) s.insert(v);
            }
            v.clear();
        }
    }
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> s;
        solve(nums,k,p,s);
        return s.size();
    }
};