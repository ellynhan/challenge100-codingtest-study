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
    int prev;
    bool first = true;
    int inorderTraversal(TreeNode* root){
        int ret = 0;
        if(root == nullptr) return 0;
        if(root->left !=nullptr){
            ret += inorderTraversal(root->left);
        }
        if(first == true){
            prev = root->val;
            first = false;
        }
        else if(prev < root->val){
            prev = root->val;
        }else{
            return 1;
        }
        if(root->right !=nullptr){
            ret += inorderTraversal(root->right);
        }
        return ret;
    }
    
    bool isValidBST(TreeNode* root) {
        int ret = 0;
        if(root != nullptr){
            ret = inorderTraversal(root);
        }
        if(ret !=0 ){
            return false;
        }else{
            return true;
        }
    }
};
