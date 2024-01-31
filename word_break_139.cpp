class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size()==0) return false;
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        int longestLength=0;
        for(auto i:wordDict) longestLength=max(longestLength,(int)i.size());
        for(int i=1;i<=s.size();i++){
            for(int j=i-1;j>=max(i-longestLength,0);j--){
                if(dp[j]){
                    string word=s.substr(j,i-j);
                    if(find(wordDict.begin(),wordDict.end(),word)!=wordDict.end()){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};