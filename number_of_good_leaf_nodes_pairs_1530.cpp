/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int> dfs(TreeNode *root,int distance,int &ans){
        if(!root) return {};
        if(!root->left&&!root->right) return {0};
        vector<int> left=dfs(root->left,distance,ans),right=dfs(root->right,distance,ans);
        for(int &l:left){
            for(int &r:right){
                if(l+1+r<=distance-1) ans++;
            }
        }
        vector<int> v;
        for(int &l:left){
            if(l+1<distance) v.emplace_back(l+1);
        }
        for(int &r:right){
            if(r+1<distance) v.emplace_back(r+1);
        }
        return v;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        int ans=0;
        dfs(root,distance,ans);
        return ans;
    }
};