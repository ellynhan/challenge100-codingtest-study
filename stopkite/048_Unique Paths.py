class Solution:
    def uniquePaths(self, m, n):
        memo = [[-1] * n for _ in range(m)]

        def dp(r, c):
            if r == 0 or c == 0:
                memo[r][c] = 1

            elif memo[r][c] == -1:
                memo[r][c] = dp(r - 1, c) + dp(r, c - 1)

            return memo[r][c]

        return dp(m - 1, n - 1)


solution = Solution()
solution.uniquePaths(3, 7)
solution.uniquePaths(3, 2)
