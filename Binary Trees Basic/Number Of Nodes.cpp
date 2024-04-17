// Number Of Nodes
// https://www.naukri.com/code360/problems/number-of-nodes_8162204?leftPanelTabValue=PROBLEM

int numberOfNodes(int N){
    return pow(2, N-1);
}

// For nth level a binary tree can have max 2^(n-1) nodes
