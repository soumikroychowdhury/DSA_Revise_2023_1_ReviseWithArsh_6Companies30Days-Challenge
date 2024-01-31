class Solution {
    int dfs(int i,string &s,set<string> &st,vector<int> &dp){
        if(i==s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int res=1+dfs(i+1,s,st,dp);
        for(int j=i;j<s.size();j++){
            if(st.find(s.substr(i,j-i+1))!=st.end()) res=min(res,dfs(j+1,s,st,dp));
        }
        return dp[i]=res;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> st;
        for(auto i:dictionary) st.insert(i);
        vector<int> dp(s.size(),-1);
        return dfs(0,s,st,dp);
    }
};