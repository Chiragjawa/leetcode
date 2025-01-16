class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        
        // Connect the left child
        if (root->left != nullptr) {
            if (root->right != nullptr) {
                root->left->next = root->right;
            } else {
                root->left->next = findnext(root->next);
            }
        }
        
        // Connect the right child
        if (root->right != nullptr) {
            root->right->next = findnext(root->next);
        }
        
        // Recursively process the right child first
        connect(root->right);
        connect(root->left);
        
        return root;
    }

private:
    Node* findnext(Node* node) {
        while (node != nullptr) {
            if (node->left != nullptr) {
                return node->left;
            }
            if (node->right != nullptr) {
                return node->right;
            }
            node = node->next;
        }
        return nullptr;
    }
};
