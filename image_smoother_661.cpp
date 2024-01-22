class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m=img.size(),n=img[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum=0,count=0;
                for(int k=-1;k<=1;k++){
                    for(int l=-1;l<=1;l++){
                        if(i+k>=0&&i+k<m&&j+l>=0&&j+l<n){
                            sum+=img[i+k][j+l];
                            count++;
                        }
                    }
                }
                ans[i][j]=sum/count;
            }
        }
        return ans;
    }
};