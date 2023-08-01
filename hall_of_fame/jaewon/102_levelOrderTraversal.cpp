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
    vector<vector<int>> ret;
    
    void bfs(TreeNode* root){
        queue<pair<TreeNode*, int> > q;
        q.push({root,0});
        
        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int level = q.front().second;
            if(level >= ret.size()){
                ret.resize(ret.size()+1);
            }
            q.pop();
            ret[level].push_back(curr->val);
            if(curr->left != nullptr){
                q.push({curr->left, level+1});
            }
            if(curr->right != nullptr){
                q.push({curr->right, level+1});
            }
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root != nullptr){     
            bfs(root);   
        }
        return ret;
    }
};
