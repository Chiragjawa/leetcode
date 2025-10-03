class Solution {
private:
    bool helper(TreeNode* root, long long low, long long high) {
        if (!root) return true; 
        
        if (root->val <= low || root->val >= high) return false; 
        
        return helper(root->left, low, root->val) && 
               helper(root->right, root->val, high);
    }

public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};
  