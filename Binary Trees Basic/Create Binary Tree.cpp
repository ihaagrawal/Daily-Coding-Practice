// Create Binary Tree (EASY)
// https://www.naukri.com/code360/problems/create-binary-tree_8360671?leftPanelTabValue=PROBLEM

Node* newn(int val){
    Node* newnode = new Node(val);
    newnode->left=nullptr;
    newnode->right=nullptr;
    return newnode;
}

Node* create(Node* root, vector<int>& arr, int i, int n){
    if(i>=n ) return nullptr;

    root = newn(arr[i]);

    root->left = create(root, arr, 2*i+1, n);
    root->right = create(root, arr, 2*i+2, n);

    return root;
}


Node* createTree(vector<int>&arr){
    Node* root;
    return create(root, arr, 0, arr.size());
}
