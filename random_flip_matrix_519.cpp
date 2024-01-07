class Solution {
    map<int,int> mp;
    int m,n,count;
public:
    Solution(int m, int n) {
        srand(time(0));
        this->m=m;
        this->n=n;
        reset();
    }
    
    vector<int> flip() {
        int i=rand()%count--;
        int a=mp.find(i)!=mp.end()?mp[i]:i;
        mp[i]=mp.find(count)!=mp.end()?mp[count]:count;
        mp[count]=a;
        return {a/n,a%n};
    }
    
    void reset() {
        count=m*n;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */