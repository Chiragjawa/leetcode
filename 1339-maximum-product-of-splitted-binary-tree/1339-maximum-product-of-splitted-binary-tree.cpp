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
    int MOD = 1e9+7;
    long long ans = INT_MIN, total =0;
    int totalsum(TreeNode* root){
        if(!root) return 0;
        total = root->val + totalsum(root->left) + totalsum(root->right);
        // cout<<total<<endl;
        return total;
    }

    int dfs(TreeNode* root){
        if(!root) return 0;

        int sum = root->val + dfs(root->left)+ dfs(root->right);
        ans = (max(ans,(total-sum)*sum));
        return sum;
    }
public:
    int maxProduct(TreeNode* root) {
        totalsum(root);
        dfs(root);
        return ans %MOD;
    }
};