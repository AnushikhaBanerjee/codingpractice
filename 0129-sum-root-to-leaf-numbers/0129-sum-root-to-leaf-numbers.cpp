class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int currentSum) {
        if (!node) return 0;

        // Build the number along the path
        currentSum = currentSum * 10 + node->val;

        // If it's a leaf, return the number
        if (!node->left && !node->right) {
            return currentSum;
        }

        // Otherwise, recurse on children
        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna