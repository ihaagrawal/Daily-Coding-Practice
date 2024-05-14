// 947. Most Stones Removed with Same Row or Column (MEDIUM)
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/

class Solution {
public:
    void unionBySize(vector<int>& parent, vector<int>& size, int v, int u) {
        int pv = findParent(parent, v);
        int pu = findParent(parent, u);

        if (pv == pu) return;

        if (size[pv] >= size[pu]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    int findParent(vector<int>& parent, int x) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent, parent[x]);
    }

    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0, n = stones.size();

        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        vector<int> parent(maxRow + maxCol + 2);
        for (int i = 0; i <= maxRow + maxCol + 1; i++) 
            parent[i] = i;

        vector<int> size(maxRow + maxCol + 2, 1);

        unordered_map<int, int> st;
        for (auto stone : stones) {
            int v = stone[0], u = stone[1] + maxRow + 1;  
            unionBySize(parent, size, v, u);
            st[v] = 1;
            st[u] = 1;
        }

        int count = 0;
        for (auto it : st) {
            if (findParent(parent, it.first) == it.first) 
                count++;
        }

        return n - count;
    }
};
