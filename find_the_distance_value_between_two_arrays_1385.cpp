class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans=0;
        for(int &a:arr1){
            bool check=1;
            for(int &b:arr2){
                if(abs(a-b)<=d){check=0;break;}
            }
            ans+=check;
        }
        return ans;
    }
};