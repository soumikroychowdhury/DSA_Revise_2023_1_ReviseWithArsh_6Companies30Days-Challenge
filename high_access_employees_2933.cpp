class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> ans;
        sort(access_times.begin(),access_times.end());
        map<string,vector<string>> m;
        for(auto &i:access_times) m[i[0]].push_back(i[1]);
        for(auto &k:m){
            int n=k.second.size();
            if(n<3) continue;
            int i=0,j=2;
            while(j<n){
                string s1=k.second[i].substr(0,2),s2=k.second[j].substr(0,2),s3=k.second[i].substr(2,4),s4=k.second[j].substr(2,4);
                if((s1==s2)||(stoi(s2)-stoi(s1)==1&&stoi(s3)>stoi(s4))){
                    ans.push_back(k.first);
                    break;
                }
                i++,j++;
            }
        }
        return ans;
    }
};