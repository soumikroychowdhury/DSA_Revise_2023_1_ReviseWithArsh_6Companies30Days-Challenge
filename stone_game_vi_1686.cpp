class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<int> ans(2);
        vector<vector<int>> v;
        int n=aliceValues.size();
        for(int i=0;i<n;i++) v.push_back({-aliceValues[i]-bobValues[i],aliceValues[i],bobValues[i]});
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++) ans[i%2]+=v[i][1+i%2];
        return ans[0]==ans[1]?0:ans[0]>ans[1]?1:-1;
    }
};