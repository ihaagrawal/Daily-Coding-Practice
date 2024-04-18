// 104. Maximum Depth of Binary Tree (EASY)
// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

// Space: O(height), Time: O(n)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        int left_count=1, right_count=1;
        left_count+=maxDepth(root->left);
        right_count+=maxDepth(root->right);
        return max(left_count, right_count);
    }
};
