class Solution {
    bool check(string &s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    void solve(int i,string &s,string &s1,string &s2,int &ans){
        if(i==s.size()){
            if(check(s1)&&check(s2)) ans=max(ans,(int)s1.size()*(int)s2.size());
            return;
        }
        s1.push_back(s[i]);
        solve(i+1,s,s1,s2,ans);
        s1.pop_back();
        s2.push_back(s[i]);
        solve(i+1,s,s1,s2,ans);
        s2.pop_back();
        solve(i+1,s,s1,s2,ans);
    }
public:
    int maxProduct(string s) {
        int ans=0;
        string s1="",s2="";
        solve(0,s,s1,s2,ans);
        return ans;
    }
};