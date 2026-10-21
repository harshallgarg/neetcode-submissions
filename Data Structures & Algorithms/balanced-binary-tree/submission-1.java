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

    boolean isTreeBalanced = true;

    public int checkIfBalanced(TreeNode root){
        if(root==null)
        return 0;

        int left = checkIfBalanced(root.left);
        int right = checkIfBalanced(root.right);

        if(Math.abs(left-right)>1)
        isTreeBalanced = false;

        return 1+Math.max(left,right);
    }

    public boolean isBalanced(TreeNode root) {
        
        checkIfBalanced(root);
        return isTreeBalanced;
    }
}
