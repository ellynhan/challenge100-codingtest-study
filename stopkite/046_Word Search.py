class Solution:
    def exist(self, board, word):
        n, m = len(board[0]), len(board)
        visited = [[False] * n for _ in range(m)]

        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]

        def backtracking(x, y, w):
            if not visited[x][y] and board[x][y] == word[w]:
                if w == len(word) - 1:
                    return True
                visited[x][y] = True
                flag = False

                for i in range(4):
                    nx = dx[i] + x
                    ny = dy[i] + y

                    if nx < 0 or nx >= m or ny < 0 or ny >= n:
                        continue

                    if backtracking(nx, ny, w + 1):
                        flag = True

                visited[x][y] = False
                return flag

        for x in range(m):
            for y in range(n):
                if backtracking(x, y, 0):
                    return True
        return False


solution = Solution()
# print(solution.exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], "ABCCED"))
print(solution.exist([["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]], "SEE"))
