class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int ans=0,mask=0;
        set<int> s;
        for(string &startWord:startWords){
            mask=0;
            for(char &c:startWord) mask|=(1<<(c-'a'));
            s.insert(mask);
        }
        for(string &targetWord:targetWords){
            mask=0;
            for(char &c:targetWord) mask|=(1<<(c-'a'));
            for(char &c:targetWord){
                if(s.find(mask-(1<<(c-'a')))!=s.end()){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};