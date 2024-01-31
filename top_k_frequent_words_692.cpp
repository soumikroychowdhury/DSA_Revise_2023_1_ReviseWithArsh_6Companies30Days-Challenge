class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        map<string,int> m;
        for(string &word:words) m[word]++;
        vector<pair<string,int>> v(m.begin(),m.end());
        sort(v.begin(),v.end(),[](pair<string,int> &a,pair<string,int> &b){
            if(a.second!=b.second) return a.second>b.second;
            return a.first<b.first;
        });
        int i=0,n=v.size();
        while(i<k&&i<n){
            ans.push_back(v[i].first);
            i++;
        }
        return ans;
    }
};