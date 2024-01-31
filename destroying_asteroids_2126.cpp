class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long a=mass;
        sort(asteroids.begin(),asteroids.end());
        for(int &asteroid:asteroids){
            if(a<asteroid) return false;
            a+=asteroid;
        }
        return true;
    }
};