// 144. Binary Tree Preorder Traversal (EASY)
// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

class Solution {
public:

    void preorder(TreeNode* root, vector<int>& temp){
        if(!root) return;

        temp.push_back(root->val);
        preorder(root->left, temp);
        preorder(root->right, temp);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>temp;
        preorder(root, temp);
        return temp;
    }
};
