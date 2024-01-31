class Solution {
    const int mod=1e9+7;
public:
    int maximumProduct(vector<int>& nums, int k) {
        long long ans=1;
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        while(k--) {
            int mn = pq.top();
            pq.pop();
            pq.push(mn + 1);
        }
        while(!pq.empty()) {
            ans = ((ans % mod) * (pq.top() % mod)) % mod;
            pq.pop();
        }
        return (int)ans;
    }
};