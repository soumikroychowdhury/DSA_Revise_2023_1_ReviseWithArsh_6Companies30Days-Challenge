class Solution {
    bool check(int x,int y){
        return y>0.5*x+7&&y<=x;
    }
public:
    int numFriendRequests(vector<int>& ages) {
        int ans=0;
        map<int,int> m;
        for(int &age:ages) m[age]++;
        for(auto &[a,b]:m){
            for(auto &[c,d]:m){
                if(check(a,c)) ans+=b*(d-(a==c));
            }
        }
        return ans;
    }
};