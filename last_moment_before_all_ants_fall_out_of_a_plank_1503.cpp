class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int l=INT_MIN,r=INT_MAX;
        for(int &i:left) l=max(l,i);
        for(int &i:right) r=min(r,i);
        return max(l,n-r);
    }
};