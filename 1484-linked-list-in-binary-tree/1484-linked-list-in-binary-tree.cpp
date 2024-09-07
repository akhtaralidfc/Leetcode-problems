/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool solve(ListNode* head, ListNode *cur, TreeNode* root){
        if(cur==NULL) return true;
        if(root==NULL) return false;
        // cout<<cur->val<<":"<<root->val<<"$$";
        if(cur->val==root->val) cur=cur->next;
        else if(head->val==root->val) head=head->next;
        else cur=head;
        return solve(head,cur,root->left) || solve(head,cur,root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return solve(head,head,root);
    }
};