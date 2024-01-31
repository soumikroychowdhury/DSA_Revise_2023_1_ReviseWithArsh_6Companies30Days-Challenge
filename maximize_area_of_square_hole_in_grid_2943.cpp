class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int ans=0,h=0,v=0,diff=1;
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]-hBars[i-1]==1){
                diff++;
                continue;
            }
            h=max(h,diff);
            diff=1;
        }
        h=max(h,diff);
        diff=1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i]-vBars[i-1]==1){
                diff++;
                continue;
            }
            v=max(v,diff);
            diff=1;
        }
        v=max(v,diff);
        return pow(min(h,v)+1,2);
    }
};