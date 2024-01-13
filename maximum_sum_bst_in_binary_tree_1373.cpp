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
    vector<int> solve(TreeNode *root,int &ans){
        if(!root) return {INT_MAX,INT_MIN,0};
        vector<int> l=solve(root->left,ans),r=solve(root->right,ans);
        if(l.empty()||r.empty()||root->val<=l[1]||root->val>=r[0]) return {};
        int sum=root->val+l[2]+r[2];
        ans=max(ans,sum);
        int mn=min(root->val,l[0]),mx=max(root->val,r[1]);
        return {mn,mx,sum};
    }
public:
    int maxSumBST(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};