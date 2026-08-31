class Solution {
public:
    void inorder(TreeNode* root, vector<int>& nodes) {
        if (!root) return;
        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nodes;
        inorder(root, nodes);   // Collect all nodes in sorted order
        return nodes[k-1];      // k is 1-indexed
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna