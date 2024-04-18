// 543. Diameter of Binary Tree (EASY)
// https://leetcode.com/problems/diameter-of-binary-tree/description/

//Space: O(n)->Recursive Stack, Time: O(n)
class Solution {
public:

    int height(TreeNode* root, int& h){
        if(!root) return 0;

        int lh=height(root->left, h);
        int rh=height(root->right, h);
        h=max(h, abs(lh+rh));
        return max(lh, rh)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int h=0;
        height(root, h);
        return h;
    }
};
