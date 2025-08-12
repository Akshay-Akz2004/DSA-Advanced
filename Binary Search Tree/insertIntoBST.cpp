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
    void helper(TreeNode*root,int val){
        if(!root) return;
        if(root->val>val and !root->left){
            root->left=new TreeNode(val);
            return;
        }

        if(root->val<val and !root->right){
            root->right=new TreeNode(val);
            return;
        }

        if(root->val>val) helper(root->left,val);
        else helper(root->right,val);

        return;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode*newnode=new TreeNode(val);
            return newnode;
        }

        helper(root,val);
        return root;
    }
};