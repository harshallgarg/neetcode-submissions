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

    public int traverse(TreeNode root, int maxVal){
        
        if(root==null)
        return 0;

        int leftSubTreeGoodNodes = traverse(root.left,Math.max(maxVal,root.val));
        int rightSubTreeGoodNodes = traverse(root.right,Math.max(maxVal,root.val));

        return leftSubTreeGoodNodes + rightSubTreeGoodNodes + (maxVal<=root.val?1:0);
    }

    public int goodNodes(TreeNode root) {
        
        if(root==null)
        return 0;

        int maxVal = root.val;
        return traverse(root,maxVal);
    }
}
