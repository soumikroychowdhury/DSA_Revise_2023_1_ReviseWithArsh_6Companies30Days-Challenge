class Solution {
public:
    int countCollisions(string directions) {
        int ans=0,n=directions.size();
        int left=0,right=n-1;
        while(left<n&&directions[left]=='L') left++;
        while(right>=0&&directions[right]=='R') right--;
        for(int i=left;i<=right;i++) ans+=directions[i]!='S';
        return ans;
    }
};