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
    vector<TreeNode*> inorder;
    
    void getInorderNodes(TreeNode* root){ //inorder로 순회하면 결과값이 이미 sort되어있음
        if(root == nullptr) return;
        getInorderNodes(root->left);
        inorder.push_back(root);
        getInorderNodes(root->right);
    }
    
    TreeNode* inorderTraversal(int start, int end){
        if(start>end) return nullptr;
        int mid = (end+start)/2;
        TreeNode* ret = inorder[mid];
        ret->left = inorderTraversal(start,mid-1);
        ret->right = inorderTraversal(mid+1,end);
        return ret;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        getInorderNodes(root);
        return inorderTraversal(0,inorder.size()-1);
    }
};
