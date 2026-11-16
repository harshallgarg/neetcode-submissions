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

    int traverse(TreeNode* root, int &maxAns){
        if(root==NULL)
        return 0;

        int left = traverse(root->left, maxAns);
        int right = traverse(root->right, maxAns);

        int sum = max(root->val+left, max(root->val+right, max(root->val+left+right, root->val)));

        maxAns = max(sum,maxAns);

        return max(root->val+left,max(root->val,root->val+right));
    }

    int maxPathSum(TreeNode* root) {

        int maxAns = INT_MIN;

        traverse(root, maxAns);
        return maxAns;
    }
};
;