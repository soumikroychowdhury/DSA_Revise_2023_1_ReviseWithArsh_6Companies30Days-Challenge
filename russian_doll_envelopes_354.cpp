class Solution {
    static bool compare(vector<int> &i,vector<int> &j){
        if(i[0]==j[0]) return i[1]>j[1];
        return i[0]<j[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> ans;
        sort(envelopes.begin(),envelopes.end(),compare);
        for(vector<int> &envelope:envelopes){
            auto it=lower_bound(ans.begin(),ans.end(),envelope[1]);
            if(it==ans.end()) ans.push_back(envelope[1]);
            else *it=envelope[1];
        }
        return ans.size();
    }
};