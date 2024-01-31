class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(),dictionary.end(),[](string &a,string &b){
            return a.size()!=b.size()?a.size()>b.size():a<b;
        });
        for(string &word:dictionary){
            int i=0,n=word.size();
            for(char &c:s){
                if(i<n&&word[i]==c) i++;
            }
            if(i==n) return word;
        }
        return "";
    }
};