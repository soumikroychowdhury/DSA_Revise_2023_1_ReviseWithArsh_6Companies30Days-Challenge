class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        int ans=abs(start[0]-target[0])+abs(start[1]-target[1]),n=specialRoads.size();
        vector<int> dist(n,1e7);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            dist[i]=abs(start[0]-specialRoads[i][0])+abs(start[1]-specialRoads[i][1])+specialRoads[i][4];
            pq.push({dist[i],i});
        }
        while(!pq.empty()){
            auto [d1,a]=pq.top();pq.pop();
            if(d1>dist[a]) continue;
            ans=min(ans,d1+abs(target[0]-specialRoads[a][2])+abs(target[1]-specialRoads[a][3]));
            for(int i=0;i<n;i++){
                int w=abs(specialRoads[a][2]-specialRoads[i][0])+abs(specialRoads[a][3]-specialRoads[i][1])+specialRoads[i][4];
                if(d1+w<dist[i]){
                    dist[i]=d1+w;
                    pq.push({dist[i],i});
                }
            }
        }
        return ans;
    }
};