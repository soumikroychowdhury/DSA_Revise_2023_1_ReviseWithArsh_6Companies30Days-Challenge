class Solution {
    vector<string> a1={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"},a2={"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"},a3={"","Thousand","Million","Billion"};
    string solve(int n){
        if(n==0) return "";
        if(n<20) return a1[n]+" ";
        if(n<100) return a2[n/10]+" "+solve(n%10);
        return a1[n/100]+" Hundred "+solve(n%100);
    }
public:
    string numberToWords(int num) {
        if(num==0) return "Zero";
        string ans="";
        int i=0,j=0;
        while(num){
            if(num%1000) ans=solve(num%1000)+a3[i]+" "+ans;
            num/=1000;
            i++;
        }
        j=ans.size()-1;
        while(ans[j]==' ') j--;
        return ans.substr(0,j+1);
    }
};