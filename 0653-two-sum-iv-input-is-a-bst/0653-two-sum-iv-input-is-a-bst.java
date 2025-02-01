/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean solve(HashMap<Integer,Integer> m,TreeNode root, int k){
        if(root==null) return false;
        if(m.containsKey(k-root.val)) return true;
        m.put(root.val,m.getOrDefault(root.val,0)+1);
        return solve(m,root.left,k) || solve(m,root.right,k);
    }
    public boolean findTarget(TreeNode root, int k) {
        HashMap<Integer,Integer> mp=new HashMap<>();
        return solve(mp,root,k);
    }
}