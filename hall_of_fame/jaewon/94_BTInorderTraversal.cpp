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
    //재귀 풀이
    void inorder(TreeNode* node, vector<int>& answer){
        if(node->left != nullptr){
            inorder(node->left, answer);
        }
        answer.push_back(node->val);
        if(node->right != nullptr){
            inorder(node->right, answer);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        stack<TreeNode*> node;
        if(root != nullptr){
            // inorder(root, answer);
            
            //반복 풀이
            node.push(root);
            while(!node.empty()){
                TreeNode* top = node.top();
                if(top->left != nullptr){
                    node.push(top->left);
                    top->left = nullptr;
                }else{
                    answer.push_back(top->val);
                    node.pop();
                    if(top->right != nullptr){
                        node.push(top->right);
                        top->right = nullptr;
                    }
                }
            }
        }
        return answer;
    }
};