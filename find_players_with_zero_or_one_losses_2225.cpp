class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        map<int,int> m;
        for(vector<int> &i:matches){
            if(m.find(i[0])==m.end()) m[i[0]]=0;
            m[i[1]]++;
        }
        for(auto &i:m){
            if(i.second==0||i.second==1) ans[i.second].emplace_back(i.first);
        }
        return ans;
    }
};