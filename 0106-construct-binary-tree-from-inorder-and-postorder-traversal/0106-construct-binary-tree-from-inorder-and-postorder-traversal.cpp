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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>index;
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }
        return createtree(inorder , postorder, 0,inorder.size()-1, 0,postorder.size()-1,index);
    }
    TreeNode* createtree(vector<int>& inorder, vector<int>& postorder,int is,int ie,int ps,int pe,unordered_map<int, int>& index){
        if(is>ie ||ps>pe){
            return nullptr;
        }
        int rootval =postorder[pe];
        TreeNode* root =new TreeNode(rootval);
        int inorderindex =index[rootval];
        int lefttree = inorderindex - is;
        root->left =createtree (inorder ,postorder,is,inorderindex-1 , ps,ps+lefttree-1,index);
        root->right =createtree (inorder ,postorder,inorderindex+1,ie,ps+lefttree,pe-1,index);
        return root;
    }
};