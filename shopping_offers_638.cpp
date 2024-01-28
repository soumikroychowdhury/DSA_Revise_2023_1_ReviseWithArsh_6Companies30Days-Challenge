class Solution {
    int solve(int index,vector<int> &price, vector<vector<int>> &special, vector<int> &needs){
        int mn=direct(price,needs);
        for(int i=index;i<special.size();i++){
            vector<int> v,offer=special[i];
            for(int j=0;j<needs.size();j++){
                if(needs[j]<offer[j]){
                    v.clear();
                    break;
                }
                v.push_back(needs[j]-offer[j]);
            }
            if(v.size()) mn=min(mn,offer.back()+solve(i,price,special,v));
        }
        return mn;
    }
    int direct(vector<int> &price,vector<int> &needs){
        int ans=0;
        for(int i=0;i<price.size();i++) ans+=price[i]*needs[i];
        return ans;
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return solve(0,price,special,needs);
    }
};