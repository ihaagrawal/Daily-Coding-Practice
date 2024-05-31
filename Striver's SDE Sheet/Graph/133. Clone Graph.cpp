// 133. Clone Graph (MEDIUM)
// https://leetcode.com/problems/clone-graph/description/

//APPROACH
//Clone the given node
//Apply DFS on the node
//If the node adjacent to current node has not been cloned yet,
//  then clone it and add it to the current nodes neighbors
//If the node adjacent to the current node has already been cloned
//  then simply add it to the neighbors of current node
//To check if the node has been cloned or not we maintain a map
//The map stores the original node and it's corresponding cloned node


//SOLUTION:

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    void helper(Node* node, Node* clone_node, map<Node*,Node*>& mp){

        //if the node hasn't been cloned yet
        for(Node* neigh : node->neighbors){
            if(mp.find(neigh) == mp.end()){

                //clone the node and add it to map and the current node's neigbors
                Node* clone = new Node(neigh->val);
                mp[neigh] = clone;
                clone_node->neighbors.push_back(clone);
                helper(neigh, clone, mp);
            }else{
                //if node has been cloned already add it to current node's neighbors
                clone_node->neighbors.push_back(mp[neigh]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        
        //if no node is present
        if (node == nullptr) return nullptr;

        //clone the given node
        Node* clone_node = new Node(node->val);

        //maintain the map
        map<Node*,Node*> mp;

        //add the orginal and cloned node to map
        mp[node] = clone_node;

        //call dfs on the node
        helper(node, clone_node, mp);
        return clone_node;
    }
};

