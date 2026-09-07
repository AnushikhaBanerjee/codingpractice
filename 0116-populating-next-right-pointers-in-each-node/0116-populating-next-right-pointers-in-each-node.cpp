class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        // Start from the leftmost node of each level
        Node* leftmost = root;

        while (leftmost->left) {
            Node* head = leftmost;

            while (head) {
                // Connect left → right
                head->left->next = head->right;

                // Connect right → next left (if exists)
                if (head->next) {
                    head->right->next = head->next->left;
                }

                // Move horizontally using next pointers
                head = head->next;
            }

            // Move down to the next level
            leftmost = leftmost->left;
        }

        return root;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna