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
    int preorderindex = 0;
    unordered_map<int, int> inordermap;

    TreeNode* constructtree(vector<int>& preorder, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        // Get the current root value and increment preorder index
        int rootvalue = preorder[preorderindex++];
        TreeNode* root = new TreeNode(rootvalue);

        // Find the root index in the inorder traversal
        int rootindex = inordermap[rootvalue];

        // Recursively build the left and right subtrees
        root->left = constructtree(preorder, left, rootindex - 1);
        root->right = constructtree(preorder, rootindex + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Fill the map with inorder values and their indices
        for (int i = 0; i < inorder.size(); i++) {
            inordermap[inorder[i]] = i;
        }

        // Build the binary tree
        return constructtree(preorder, 0, inorder.size() - 1);
    }
};
