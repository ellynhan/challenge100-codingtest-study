package Easy;

import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode id=104 lang=java
 *
 * [104] Maximum Depth of Binary Tree
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
    public int maxDepth(TreeNode root) {
        return countDepth(root, 0);
    }

    private int countDepth(TreeNode node, int depth) {
        if (node == null)
            return depth;
        int leftDepth = countDepth(node.left, depth + 1);
        int rightDepth = countDepth(node.right, depth + 1);
        return Math.max(leftDepth, rightDepth);
    }
}
// @lc code=end
