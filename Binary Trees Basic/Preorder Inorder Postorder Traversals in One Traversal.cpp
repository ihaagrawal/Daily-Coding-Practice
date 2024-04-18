// Tree Traversals (EASY)
// https://www.naukri.com/code360/problems/tree-traversals_981269?leftPanelTabValue=PROBLEM


vector<vector<int>> getTreeTraversal(TreeNode *root){
    if(!root) return {};
    vector<int> pre, ino, post;
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});
    while(!st.empty()){
        auto it=st.top();
        st.pop();

        if(it.second==1){
            pre.push_back(it.first->data);
            it.second=2;
            st.push(it);
            if(it.first->left) st.push({it.first->left, 1});
        }

        else if(it.second==2){
            ino.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right) st.push({it.first->right, 1});
        }

        else post.push_back(it.first->data);
    }
    return {ino, pre, post};
}
