 def maxDepth(self, root: Optional[TreeNode]) -> int:
        Q = collections.deque()
        if not root: return 0
        Q.append(root)
        depth = 0
        while Q:
            depth += 1
            for _ in range(len(Q)):
                node = Q.popleft()
                if node.left:
                    Q.append(node.left)
                if node.right:
                    Q.append(node.right)
        return depth
