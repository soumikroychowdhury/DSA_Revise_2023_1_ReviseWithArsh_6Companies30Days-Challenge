class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ans(rows*cols,vector<int>(2));
        vector<vector<bool>> vis(rows,vector<bool>(cols));
        int i=0;
        queue<pair<int,int>> q;
        q.push({rCenter,cCenter});
        while(!q.empty()){
            auto [a,b]=q.front();q.pop();
            if(a<0||a>=rows||b<0||b>=cols||vis[a][b]) continue;
            ans[i++]={a,b};
            vis[a][b]=1;
            q.push({a,b-1});q.push({a,b+1});q.push({a-1,b});q.push({a+1,b});
        }
        return ans;
    }
};