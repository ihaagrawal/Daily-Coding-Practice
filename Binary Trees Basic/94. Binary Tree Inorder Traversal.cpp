// 94. Binary Tree Inorder Traversal (EASY)
// https://leetcode.com/problems/binary-tree-inorder-traversal/description/

class Solution {
public:

    void inorder(TreeNode* root, vector<int>& temp){
        if(!root) return;

        inorder(root->left, temp);
        temp.push_back(root->val);
        inorder(root->right, temp);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>temp;
        inorder(root, temp);
        return temp;
    }
};
