class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Step 1: Build adjacency list
        vector<vector<int>> adj(n);
        for (auto &edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
        }

        // Step 2: Find suspicious set S using DFS
        vector<bool> suspicious(n, false);
        stack<int> st;
        st.push(k);
        suspicious[k] = true;

        while (!st.empty()) {
            int u = st.top(); st.pop();
            for (int v : adj[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = true;
                    st.push(v);
                }
            }
        }

        // Step 3: Check external invocations
        for (auto &edge : invocations) {
            int u = edge[0], v = edge[1];
            if (suspicious[v] && !suspicious[u]) {
                // External method invokes suspicious → cannot remove
                vector<int> all(n);
                iota(all.begin(), all.end(), 0);
                return all;
            }
        }

        // Step 4: Collect remaining methods
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) result.push_back(i);
        }
        return result;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna