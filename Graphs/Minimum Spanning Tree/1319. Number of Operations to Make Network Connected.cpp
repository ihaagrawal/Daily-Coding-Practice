// 1319. Number of Operations to Make Network Connected (MEDIUM)
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

class Solution {
public:

    int findParent(vector<int>& parent, int v){
        if(parent[v]==v) return v;

        return parent[v] = findParent(parent, parent[v]);
    }

    void unionBySize(vector<int>& size, vector<int>& parent, int v, int u){
        int pv = findParent(parent, v), pu = findParent(parent, u);

        if(size[pv]>=size[pu]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;

        vector<int> parent(n);
        for(int i=0;i<n;i++) parent[i]=i;

        vector<int> size(n, 1);

        int extra=0;
        for(auto& con:connections){
            int v=con[0], u=con[1];
            if(findParent(parent, v) != findParent(parent, u)){
                unionBySize(size, parent, v, u);
            }else{
                extra++;
            }
        }

        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(findParent(parent, i));
        }

        int nc = st.size();
        if(extra >= nc-1) return nc-1;
        return -1;
    }
};
