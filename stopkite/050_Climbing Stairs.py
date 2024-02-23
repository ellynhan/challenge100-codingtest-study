class Solution:
    def climbStairs(self, n):
        memo = [-1] * (n + 1)

        def dp(n):
            if n == 0 or n == 1:
                return 1

            if memo[n] == -1:
                memo[n] = dp(n - 1) + dp(n - 2)

            return memo[n]

        return dp(n)


solution = Solution()
solution.climbStairs(2)
solution.climbStairs(3)
