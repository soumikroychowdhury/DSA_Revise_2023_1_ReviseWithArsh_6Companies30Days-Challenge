class WordDictionary {
public:
    vector<WordDictionary*> child;
    bool isend;
    WordDictionary():isend(false) {
        child=vector<WordDictionary*>(26,NULL);
    }
    
    void addWord(string word) {
        WordDictionary* cur=this;
        for(char c:word){
            if(cur->child[c-'a']==NULL) cur->child[c-'a']=new WordDictionary();
            cur=cur->child[c-'a'];
        }
        cur->isend=true;
    }
    
    bool search(string word) {
        WordDictionary* cur=this;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(ch=='.'){
                for(auto c:cur->child) if(c && c->search(word.substr(i+1))) return true;
                return false;
            }
            if(cur->child[ch-'a']==NULL) return false;
            cur=cur->child[ch-'a'];
        }
        return cur&&cur->isend;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */