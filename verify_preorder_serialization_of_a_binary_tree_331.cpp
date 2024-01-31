class Solution {
public:
    bool isValidSerialization(string preorder) {
        istringstream s(preorder);
        vector<string> nodes;
        string node;
        while(getline(s,node,',')) nodes.push_back(node);
        int diff=1;
        for(string &i:nodes){
            if(--diff<0) return false;
            if(i!="#") diff+=2;
        }
        return diff==0;
    }
};