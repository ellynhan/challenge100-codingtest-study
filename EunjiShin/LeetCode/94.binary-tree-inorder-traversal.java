package Easy;

import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode id=94 lang=java
 *
 * [94] Binary Tree Inorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    List<Integer> answer;

    public List<Integer> inorderTraversal(TreeNode root) {
        answer = new ArrayList<>();
        inorder(root);
        return answer;
    }

    private void inorder(TreeNode node) {
        if (node != null) {
            if (node.left != null) {
                inorder(node.left);
            }
            answer.add(node.val);
            if (node.right != null) {
                inorder(node.right);
            }
        }
    }
}
// @lc code=end
