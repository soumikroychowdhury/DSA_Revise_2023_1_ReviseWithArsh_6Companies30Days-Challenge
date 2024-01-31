class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans=0,count=0;
        map<int,vector<int>> m;
        for(vector<int> &seat:reservedSeats) m[seat[0]-1].push_back(seat[1]-1);
        ans=2*(n-m.size());
        for(auto &[a1,v1]:m){
            vector<bool> v(10);
            for(int &i:v1) v[i]=1;
            bool a=1,b=1;
            count=0;
            for(int i=1;i<9;i++) count+=v[i];
            if(count==0){ans+=2;continue;}
            count=0;
            for(int i=1;i<5;i++) count+=v[i];
            if(count==0) a=0,ans++;
            count=0;
            for(int i=5;i<9;i++) count+=v[i];
            if(count==0) b=0,ans++;
            if(a&&b){
                count=0;
                for(int i=3;i<7;i++) count+=v[i];
                if(count==0) ans++;
            }
        }
        return ans;
    }
};