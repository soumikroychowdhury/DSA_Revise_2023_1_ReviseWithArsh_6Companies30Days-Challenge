class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        if(source.size()!=target.size()) return -1;
        long long ans=0;
        vector<vector<long long>> dis(26,vector<long long>(26,1e11));
        for(int i=0;i<original.size();i++) dis[original[i]-'a'][changed[i]-'a']=min(dis[original[i]-'a'][changed[i]-'a'],(long long)cost[i]);
        int n=original.size();
        for(int i=0;i<26;i++) dis[i][i]=0;
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(dis[i][k]!=1e11&&dis[k][j]!=1e11) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        for(int i=0;i<source.size();i++){
            int a=source[i]-'a',b=target[i]-'a';
            if(dis[a][b]==1e11) return -1;
            ans+=dis[a][b];
        }
        return ans;
    }
};