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
    int sum(TreeNode* root , int number ){
        
        if(!root){
            return 0; 
        }
        number = number*10 + root->val;
        if(!root->left && !root->right){
            return number;
        }
        return sum(root->left, number ) + sum(root->right, number);
    }
public:
    int sumNumbers(TreeNode* root) {
       
        int number =0;
        return sum(root , number);
      
    }
};