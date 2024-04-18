// Postorder Traversal (EASY)
// https://www.naukri.com/code360/problems/postorder-traversal_2035933?leftPanelTabValue=PROBLEM

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int>temp;
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    st1.push(root);
    while(!st1.empty()){
        TreeNode* node=st1.top();
        if(node){
            st1.pop();
            if(node->left) st1.push(node->left);
            if(node->right) st1.push(node->right);
            st2.push(node);
        }
    }

    while(!st2.empty()){
        TreeNode* node=st2.top();
        temp.push_back(node->data);
        st2.pop();
    }
    return temp;
}
