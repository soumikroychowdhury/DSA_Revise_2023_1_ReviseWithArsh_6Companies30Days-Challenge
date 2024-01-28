class Solution {
    # define a(i) nums[(1+2*i)%(n|1)]
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,k=n-1;
        auto midptr=nums.begin()+n/2;
        nth_element(nums.begin(),midptr,nums.end());
        int mid=*midptr;
        while(j<=k){
            if(a(j)>mid) swap(a(i++),a(j++));
            else if(a(j)<mid) swap(a(j),a(k--));
            else j++;
        }
    }
};