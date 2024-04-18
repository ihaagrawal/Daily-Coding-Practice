// Tree Traversals (EASY)
// https://www.naukri.com/code360/problems/tree-traversal_981269?leftPanelTabValue=PROBLEM

void postorder(TreeNode* root, vector<int>& temp){
    if(!root) return;
    postorder(root->left, temp);
    postorder(root->right, temp);
    temp.push_back(root->data);
}


void preorder(TreeNode* root, vector<int>& temp){
   if(!root) return;

    temp.push_back(root->data);
    preorder(root->left, temp);
    preorder(root->right, temp);
}


void inorder(TreeNode* root, vector<int>& temp){
    if(!root) return;

    inorder(root->left, temp);
    temp.push_back(root->data);
    inorder(root->right, temp);
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>> result;
    vector<int> pre;
    vector<int> post;
    vector<int> ino;

    inorder(root, ino);
    preorder(root, pre);
    postorder(root, post);

    result.push_back(ino);
    result.push_back(pre);
    result.push_back(post);

    return result;
}
