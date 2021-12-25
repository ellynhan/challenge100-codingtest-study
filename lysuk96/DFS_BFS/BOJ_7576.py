#토마토
#count 출력 : len(queue) 반복 후
from collections import deque

def solution(m, n, tomatoes):

    def search(r, c):
        D = [(0,1), (0,-1), (1,0), (-1,0)]
        result = []
        for i, j in D:
            if (r+i>=0 and r+i<n)\
                and (c+j>=0 and c+j<m)\
                    and (tomatoes[r+i][c+j] == 0):
                    result.append((r+i, c+j))
        return result
    
    #initialize
    queue = deque([])
    count = 0
    for r in range(n):
        for c in range(m):
            if tomatoes[r][c] == 1:
                queue.append((r,c))

    while queue:
        # print(queue)
        for _ in range(len(queue)):
            tomato = queue.popleft()
            for i, j in search(tomato[0],tomato[1]):
                tomatoes[i][j] = 1
                queue.append((i,j))
        # print(tomatoes)
        count+=1
    
    #결과물 출력
    for r in range(n):
        for c in range(m):
            if tomatoes[r][c] == 0:
                print('-1')
                return
    print(count-1)
    return

M, N = map(int, input().split())
# tomatoes = []
# for r in range(M):
#     for c in range(N):
#         tomatoes[r][c] = int(input())
tomatoes = [[n for n in map(int,input().split())] for _ in range(N)]
# print(tomatoes)
solution(M, N, tomatoes)
