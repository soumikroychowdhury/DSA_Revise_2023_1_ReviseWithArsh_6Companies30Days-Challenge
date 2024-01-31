class Solution {
    int solve(int state,vector<vector<int>> &dist,int n){
        int mx=0,edges=0,cities=0;
        for(int i=0;i<n;i++){
            if(((state>>i)&1)==0) continue;
            cities++;
            for(int j=i+1;j<n;j++){
                if(((state>>j)&1)==0) continue;
                edges+=dist[i][j]==1;
                mx=max(mx,dist[i][j]);
            }
        }
        if(edges!=cities-1) return 0;
        return mx;
    }
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> ans(n-1);
        int mx=n;
        vector<vector<int>> dist(n,vector<int>(n,mx));
        for(auto &e:edges) dist[e[0]-1][e[1]-1]=dist[e[1]-1][e[0]-1]=1;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
        for(int state=0;state<(1<<n);state++){
            int a=solve(state,dist,n);
            if(a>0) ans[a-1]++;
        }
        return ans;
    }
};