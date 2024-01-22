class Solution {
    map<int,vector<int>> m;
    int sum=0;
public:
    Solution(vector<vector<int>>& rects) {
        for(auto &rect:rects){
            sum+=(rect[3]-rect[1]+1)*(rect[2]-rect[0]+1);
            m[sum]=rect;
        }
    }
    
    vector<int> pick() {
        int a=rand()%sum;
        auto b=m.upper_bound(a);
        vector<int> v=b->second;
        int x=v[0]+rand()%(v[2]-v[0]+1), y=v[1]+rand()%(v[3]-v[1]+1);
        return {x,y};
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */