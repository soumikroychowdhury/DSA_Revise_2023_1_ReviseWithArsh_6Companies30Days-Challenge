class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> ans,i1,i2;
        int size=s.size(),asize=a.size(),bsize=b.size();
        for(int i=0;i<=size-asize;i++){
            if(s.substr(i,asize)==a) i1.emplace_back(i);
        }
        for(int i=0;i<=size-bsize;i++){
            if(s.substr(i,bsize)==b) i2.emplace_back(i);
        }
        for(int i=0;i<i1.size();i++){
            for(int j=0;j<i2.size();j++){
                if(abs(i1[i]-i2[j])<=k){ans.push_back(i1[i]);break;}
            }
        }
        return ans;
    }
};