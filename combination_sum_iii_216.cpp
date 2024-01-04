class Solution {
    void solve(int i,int k,int n,vector<vector<int>> &ans,vector<int> &a){
        if(a.size()==k&&n==0) ans.push_back(a);
        if(a.size()==k) return;
        for(int j=i;j<=9;j++){
            a.push_back(j);
            solve(j+1,k,n-j,ans,a);
            a.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> a;
        solve(1,k,n,ans,a);
        return ans;
    }
};