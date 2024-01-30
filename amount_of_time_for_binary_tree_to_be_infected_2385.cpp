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
public:
    int amountOfTime(TreeNode* root, int start) {
        int ans=0;
        unordered_map<int,vector<int>> g;
        queue<pair<TreeNode*,int>> q1;
        q1.push({root,-1});
        while(!q1.empty()){
            auto [node,parent]=q1.front();q1.pop();
            if(parent!=-1){
                g[parent].push_back(node->val);
                g[node->val].push_back(parent);
            }
            if(node->left) q1.push({node->left,node->val});
            if(node->right) q1.push({node->right,node->val});
        }
        queue<int> q;
        unordered_set<int> vis;
        q.push(start);
        vis.insert(start);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int node=q.front();q.pop();
                for(auto &i:g[node]){
                    if(vis.find(i)==vis.end()){
                        q.push(i);
                        vis.insert(i);
                    }
                }
            }
            ++ans;
        }
        return --ans;
    }
};