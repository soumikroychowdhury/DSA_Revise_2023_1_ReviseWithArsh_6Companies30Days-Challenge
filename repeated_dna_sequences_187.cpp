class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if(s.size()<10) return ans;
        map<string,int> m;
        for(int i=0;i<s.size()-9;i++){
            if(m[s.substr(i,10)]==1) ans.emplace_back(s.substr(i,10));
            m[s.substr(i,10)]++;
        }
        return ans;
    }
};