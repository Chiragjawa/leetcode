class Solution {
private:
    void inorder(TreeNode* root, vector<int>& arr) {
        if (!root) return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> t1;
        inorder(root1, t1);
        inorder(root2, t1);
        sort(t1.begin(),t1.end());
        return t1;
    }
};
