class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long low=0,high=1e10;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(mid-mid/divisor1>=uniqueCnt1&&mid-mid/divisor2>=uniqueCnt2&&mid-mid*__gcd(divisor1,divisor2)/(1LL*divisor1*divisor2)>=(uniqueCnt1+uniqueCnt2)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};