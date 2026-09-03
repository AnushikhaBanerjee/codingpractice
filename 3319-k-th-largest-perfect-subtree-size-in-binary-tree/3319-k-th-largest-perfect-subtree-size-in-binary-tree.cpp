class Solution {
public:
    vector<int> sizes;

    // returns {isPerfect, height, size}
    tuple<bool,int,int> dfs(TreeNode* root) {
        if(!root) return {true, 0, 0};

        auto [lp, lh, ls] = dfs(root->left);
        auto [rp, rh, rs] = dfs(root->right);

        bool isPerfect = lp && rp && (lh == rh);
        int height = max(lh, rh) + 1;
        int size = ls + rs + 1;

        if(isPerfect) {
            sizes.push_back(size);
        }
        return {isPerfect, height, size};
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        dfs(root);
        sort(sizes.begin(), sizes.end(), greater<int>());
        if(k > sizes.size()) return -1;
        return sizes[k-1];
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna