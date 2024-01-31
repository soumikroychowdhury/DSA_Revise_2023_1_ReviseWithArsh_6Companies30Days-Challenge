class Solution {
    vector<int> lps(string &s){
        vector<int> lps(s.size());
        for(int i=1,j=0;i<s.size();i++){
            while(j&&s[i]!=s[j]) j=max(0,lps[j-1]);
            j+=s[i]==s[j];
            lps[i]=j;
        }
        return lps;
    }
public:
    long long sumScores(string s) {
        vector<int> ans;
        for(int &i:lps(s)) ans.push_back(i==0?0:ans[i-1]+1);
        return accumulate(ans.begin(),ans.end(),0LL)+s.size();
    }
};