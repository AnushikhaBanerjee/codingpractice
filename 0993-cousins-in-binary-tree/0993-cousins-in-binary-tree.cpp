/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode*parentX=nullptr;
        TreeNode*parentY=nullptr;
        int depthX=-1, depthY=-1;
        dfs(root,nullptr,0,x,parentX,depthX);
        dfs(root,nullptr,0,y,parentY,depthY);
        return(depthX==depthY)&&(parentX!=parentY);
    }
    private:
    void dfs(TreeNode* node,TreeNode*parent,int depth, int target, TreeNode*& parentOut, int& depthOut){
        if (!node) return;

        if (node->val == target) {
            parentOut = parent;
            depthOut = depth;
            return;
        }

        dfs(node->left, node, depth + 1, target, parentOut, depthOut);
        dfs(node->right, node, depth + 1, target, parentOut, depthOut);
    }
};
    

        
    


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna