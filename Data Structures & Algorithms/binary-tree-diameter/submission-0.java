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

    int diameter = 1;

    public int traverse(TreeNode root){
        if(root==null)
        return 0;

        int left = traverse(root.left);
        int right = traverse(root.right);

        diameter = Math.max(1+left+right,diameter);

        return 1 + Math.max(left,right);
    }

    public int diameterOfBinaryTree(TreeNode root) {
        
        traverse(root);
        return diameter-1;
    }
}
