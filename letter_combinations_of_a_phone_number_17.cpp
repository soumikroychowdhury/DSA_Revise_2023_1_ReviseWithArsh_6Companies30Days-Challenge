class Solution {
    map<int,vector<char>> m={{2,{'a','b','c'}},{3,{'d','e','f'}},{4,{'g','h','i'}},{5,{'j','k','l'}},{6,{'m','n','o'}},{7,{'p','q','r','s'}},{8,{'t','u','v'}},{9,{'w','x','y','z'}}};
    void solve(int index,string digits,int n,vector<string> &ans,string &a){
        if(index==n){
            ans.push_back(a);
            return;
        }
        for(char &i:m[digits[index]-'0']){
            a+=i;
            solve(index+1,digits,n,ans,a);
            a.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> ans;
        string a="";
        solve(0,digits,digits.size(),ans,a);
        return ans;
    }
};