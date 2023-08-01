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
    vector<int> v;
    void getNodes(TreeNode* tn){
        if(tn!=nullptr){
            v.push_back(tn->val);
            getNodes(tn->left);
            getNodes(tn->right);
        }else{
            v.push_back(-1);
        }
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        getNodes(p);
        getNodes(q);
        if(v.size()%2!=0){
            return false;
        }else{
            for(int i=0; i<v.size()/2; i++){
                if(v[i] != v[i+v.size()/2]){
                    return false;
                }
            }
            return true;
        }
    }
};
