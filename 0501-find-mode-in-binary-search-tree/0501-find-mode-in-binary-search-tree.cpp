class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> values;
        collectValues(root, values);

        // Step 1: Count frequencies
        unordered_map<int,int> freq;
        for (int v : values) {
            freq[v]++;
        }

        // Step 2: Find max frequency
        int maxFreq = 0;
        for (auto &p : freq) {
            maxFreq = max(maxFreq, p.second);
        }

        // Step 3: Collect all modes
        vector<int> modes;
        for (auto &p : freq) {
            if (p.second == maxFreq) {
                modes.push_back(p.first);
            }
        }
        return modes;
    }

private:
    void collectValues(TreeNode* node, vector<int> &values) {
        if (!node) return;
        values.push_back(node->val);
        collectValues(node->left, values);
        collectValues(node->right, values);
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna