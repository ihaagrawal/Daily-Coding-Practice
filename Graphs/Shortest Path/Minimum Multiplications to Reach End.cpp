// Minimum Operations (MODERATE)
// https://www.naukri.com/code360/problems/minimum-operations_8360665?leftPanelTabValue=PROBLEM

int minimumOperations(int n, int start, int end, vector<int> &a) {
    const int mod = 1000; // MOD value
    queue<pair<int, int>> q;
    q.push({start, 0});
    unordered_set<int> visited;
    visited.insert(start);

    while (!q.empty()) {
        int current = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (current == end) {
            return steps;
        }

        for (int x : a) {
            int next = (current * x) % mod;
            if (visited.find(next) == visited.end()) {
                q.push({next, steps + 1});
                visited.insert(next);
            }
        }
    }

    return -1;
}
