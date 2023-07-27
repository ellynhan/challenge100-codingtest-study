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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        TreeNode* left = root -> left;
        TreeNode* right = root -> right;
        
        int ret = 0;
        if(left != nullptr) ret = max(ret, maxDepth(left));
        if(right != nullptr) ret = max(ret, maxDepth(right));
        
        return ret + 1;
    }
};
