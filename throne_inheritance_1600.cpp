class ThroneInheritance {
    map<string,vector<string>> m;
    set<string> s;
    string a;
public:
    ThroneInheritance(string kingName) {
        a=kingName;
    }
    
    void birth(string parentName, string childName) {
        m[parentName].push_back(childName);
    }
    
    void death(string name) {
        s.insert(name);
    }
    
    void getOrder(string &b,vector<string> &ans){
        if(s.find(b)==s.end()) ans.push_back(b);
        for(auto &child:m[b]) getOrder(child,ans);
    }

    vector<string> getInheritanceOrder() {
        vector<string> ans;
        getOrder(a,ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */