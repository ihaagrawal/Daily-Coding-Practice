// Preorder Binary Tree (EASY)
// https://www.naukri.com/code360/problems/preorder-binary-tree_5948?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
vector<int> preOrder(TreeNode<int> * root){
    vector<int> temp;
    if(!root) return temp;
    stack<TreeNode<int>*> st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        temp.push_back(root->data);
        st.pop();
        if(root->right) st.push(root->right);
        if(root->left) st.push(root->left);
    }
    return temp;
}
