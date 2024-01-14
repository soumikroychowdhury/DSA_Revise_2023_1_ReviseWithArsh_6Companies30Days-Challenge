class Solution {
    int index(int n,int k){
        if(n==1) return 0;
        return (index(n-1,k)+k)%n;
    }
public:
    int findTheWinner(int n, int k) {
        return index(n,k)+1;
    }
};