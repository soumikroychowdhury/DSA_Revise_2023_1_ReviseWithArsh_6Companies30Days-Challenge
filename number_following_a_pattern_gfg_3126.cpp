class Solution{   
public:
    string printMinNumberForPattern(string S){
        string ans="";
        stack<int> s;
        int n=1;
        for(char &c:S){
            s.push(n);
            n++;
            if(c=='I'){
                while(!s.empty()){
                    ans+=to_string(s.top());
                    s.pop();
                }
            }
        }
        s.push(n);
        while(!s.empty()){
            ans+=to_string(s.top());
            s.pop();
        }
        return ans;
    }
};