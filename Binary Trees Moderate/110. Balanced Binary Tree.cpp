// 110. Balanced Binary Tree (EASY)
// https://leetcode.com/problems/balanced-binary-tree/description/

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

// Space: O(height), Time: O(n)
class Solution {
public:

    int bst(TreeNode* root, int& height){
        if(!root) return 0;

        int lh=bst(root->left, height)+1;
        int rh=bst(root->right, height)+1;

        if(abs(lh-rh)>1) height=0;
        return max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int height=1;
        bst(root, height);

        if(height) return true;
        return false;
    }
};
