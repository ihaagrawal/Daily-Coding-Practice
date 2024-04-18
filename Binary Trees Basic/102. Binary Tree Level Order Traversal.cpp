// 102. Binary Tree Level Order Traversal (MEDIUM)
// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

//Space: O(n), Time: O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> temp;
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
                temp.push_back(node->val);
            }
            result.push_back(temp);
        }
        return result;
    }
};
