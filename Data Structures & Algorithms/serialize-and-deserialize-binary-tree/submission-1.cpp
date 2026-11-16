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

class Codec {
public:

    void traverse(TreeNode* root, string &s){

        if(root==NULL){
            s+="N#";
            return;
        }

        s+=to_string(root->val)+"#";

        traverse(root->left,s);
        traverse(root->right,s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        traverse(root,s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return buildTree(data, i);
    }

    TreeNode* buildTree(string &s, int &i){
        
        if(s[i]=='N'){
            i++; // skip N
            i++; // skip #
            return NULL;
        }

        string number = "";

        while(s[i]!='#'){
            number+=s[i];
            i++;
        }

        i++; // skip #

        TreeNode* root = new TreeNode(stoi(number));
        root->left = buildTree(s,i);
        root->right = buildTree(s,i);

        return root;
    }

};
