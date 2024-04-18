// Inorder Traversal (EASY)
// https://www.naukri.com/code360/problems/inorder-traversal_3839605?leftPanelTabValue=PROBLEM

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> temp;
    if(!root) return temp;
    stack<TreeNode*> st;
    TreeNode* node = root;
    while(true){
        if(node){
            st.push(node);
            node=node->left;
        }
        else{
            if(st.empty()) break;
            node=st.top();
            st.pop();
            temp.push_back(node->data);
            node=node->right;
            }
        }
    return temp;
}

