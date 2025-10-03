class Solution {
private: 
    bool ident(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL || subRoot == NULL) {
            return root == subRoot;  // both must be NULL
        }
        if(root->val != subRoot->val) {
            return false;
        }
        return ident(root->left , subRoot->left) && ident(root->right , subRoot->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL) return true;  
        if(root == NULL) return false; 
        
        if(ident(root, subRoot)) return true;
        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
