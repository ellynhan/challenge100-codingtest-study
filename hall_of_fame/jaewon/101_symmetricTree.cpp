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
    
    int dfs(TreeNode* left, TreeNode* right){
        int ret = 0;
        if(left == nullptr && right == nullptr) return 0;
        if(left == nullptr || right == nullptr) return 1;
        if(left->val == right->val){
            ret += dfs(left->left, right->right);
            ret += dfs(left->right, right->left);
        }else{
            return 1;
        }
        return ret;
    }
        
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int ret = dfs(left, right);
        if(ret > 0){
            return false;
        }else{
            return true;
        }
    }
};
