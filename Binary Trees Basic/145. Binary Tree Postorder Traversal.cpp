// 145. Binary Tree Postorder Traversal (EASY)
// https://leetcode.com/problems/binary-tree-postorder-traversal/description/

class Solution {
public:

    void postorder(TreeNode* root, vector<int>& temp){
        if(!root) return;

        postorder(root->left, temp);
        postorder(root->right, temp);
        temp.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>temp;
        postorder(root, temp);
        return temp;
    }
};
