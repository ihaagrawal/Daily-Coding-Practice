// Postorder Traversal (EASY)
// https://www.naukri.com/code360/problems/postorder-traversal_2035933?leftPanelTabValue=PROBLEM

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode* visited=nullptr;
    while(root || !st.empty()){
        if(root){
            st.push(root);
            root=root->left;
        }
        else{
            TreeNode* temp = st.top();
            if(temp->right && visited!=temp->right){
                root=temp->right;
            }
            else{
                result.push_back(temp->data);
                visited=temp;
                st.pop();
            }
        }
    }
    return result;
}
