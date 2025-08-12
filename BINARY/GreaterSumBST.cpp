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
    int sum=0;
    void construct(TreeNode*root){
        if(!root) return;
        construct(root->right);
        int temp=root->val;
        root->val=root->val+sum;
        sum+=temp;
        construct(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        construct(root);
        return root;
    }
};