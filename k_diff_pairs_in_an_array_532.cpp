class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans=0;
        map<int,int> m;
        for(int &num:nums) m[num]++;
        for(auto &[a,b]:m){
            if(k==0&&b>1) ans++;
            else if(k&&m.find(a+k)!=m.end()) ans++;
        }
        return ans;
    }
};