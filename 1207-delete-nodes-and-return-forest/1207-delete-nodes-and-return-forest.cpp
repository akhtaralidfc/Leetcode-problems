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
    bool check[1001] = {};
    void dfs(TreeNode* &root,bool parent,vector<TreeNode*>& res){
        if(root==NULL) return;
        dfs(root->left,check[root->val],res);
        dfs(root->right,check[root->val],res);
        if(check[root->val]==false && parent==true){
            res.push_back(root);
        }
        if(check[root->val]==true) root=NULL;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        for(auto it:to_delete) check[it]=true;
        dfs(root,true,res);
        return res;
    }
};