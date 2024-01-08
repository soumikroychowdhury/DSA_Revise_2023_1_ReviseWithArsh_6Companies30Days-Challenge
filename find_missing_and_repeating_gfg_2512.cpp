class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int xr=0,bit=0,a=0,b=0,count=0;
        for(int i=0;i<n;i++){
            xr^=arr[i];
            xr^=(i+1);
        }
        bit=xr&~(xr-1);
        for(int i=0;i<n;i++){
            if(bit&arr[i])  a^=arr[i];
            else b^=arr[i];
            if(bit&(i+1)) a^=(i+1);
            else b^=(i+1);
        }
        for(int i=0;i<n;i++){
            if(arr[i]==a) count++;
        }
        if(count==2) return {a,b};
        return {b,a};
    }
};