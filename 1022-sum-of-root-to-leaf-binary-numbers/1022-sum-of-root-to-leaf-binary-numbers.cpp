class Solution {
public:
    vector<string> mp;

    int sumRootToLeaf(TreeNode* root) {
        if (root == nullptr) return 0;

        string cur = "";
        solve(root, cur);

        int sum = 0;
        for (string it : mp) {
            sum += stoi(it, nullptr, 2);  
        }

        return sum;
    }

    void solve(TreeNode* root, string cur) {
        if (root == nullptr) return;

        cur += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            mp.push_back(cur);
            return;
        }

        solve(root->left, cur);
        solve(root->right, cur);
    }
};