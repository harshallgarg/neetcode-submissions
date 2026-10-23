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

    // maxLeftVa<root.val

    public boolean validateBST(TreeNode root, int minVal, int maxVal){

        if(root==null)
        return true;

        if(!(root.val>minVal && root.val<maxVal))
        return false;

        boolean left = validateBST(root.left,minVal,root.val);
        boolean right = validateBST(root.right,root.val,maxVal);

        return left && right;
    }

    public boolean isValidBST(TreeNode root) {
        int minVal = Integer.MIN_VALUE;
        int maxVal = Integer.MAX_VALUE;
        return validateBST(root,minVal,maxVal);
    }
}
