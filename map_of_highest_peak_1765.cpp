class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size(),n=isWater[0].size(),height=1;
        vector<vector<int>> ans(m,vector<int>(n));
        queue<pair<int,int>> q;
        vector<int> dirs={0,1,0,-1,0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]) q.push({i,j});
                else ans[i][j]=-1;
            }
        }
        while(!q.empty()){
            int size=q.size();
            cout<<size<<" "<<height<<endl;
            while(size--){
                auto [a,b]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int x=a+dirs[i],y=b+dirs[i+1];
                    if(x>=0&&x<m&&y>=0&&y<n&&ans[x][y]==-1){
                        ans[x][y]=height;
                        q.push({x,y});
                    }
                }
            }
            height++;
        }
        return ans;
    }
};