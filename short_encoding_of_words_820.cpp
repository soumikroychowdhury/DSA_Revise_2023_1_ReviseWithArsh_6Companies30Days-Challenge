class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int ans=0;
        set<string> s(words.begin(),words.end());
        for(const string &a:s){
            for(int i=1;i<a.size();i++) s.erase(a.substr(i));
        }
        for(const string &a:s) ans+=a.size()+1;
        return ans;
    }
};