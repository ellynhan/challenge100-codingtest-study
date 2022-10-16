n, l = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
answer = 0

def check(road):
    slope = [0] * n
    for i in range(1, n):
        if road[i] == road[i-1]: continue
        elif road[i] > road[i-1] and i-l >= 0:
            for j in range(i-l, i):
                if not slope[j] and road[i]-road[j] == 1:
                    slope[j] = 1
                else: return False
        elif road[i] < road[i-1] and i+l <= n:
            for j in range(i, i+l):
                if not slope[j] and road[i-1]-road[j] == 1:
                    slope[j] = 1
                else: return False
        else: 
            return False
    return True

for road in board:
    if check(road): answer += 1
for road in list(zip(*board)):
    if check(road): answer += 1
print(answer)

"""
전치행렬(행렬의 행과 열을 맞바꾼 행렬) 만들기
# arr
[[1, 2, 3],
[4, 5, 6],
[7, 8, 9]]

for row in list(zip(*arr)):
  print(row)
    
[1, 4, 7]
[2, 5, 8]
[3, 6, 9]

+) 구현, 시뮬레이션 문제 풀 때는 체크해야할 조건이나 예외가 많으니 꼼꼼하게 따지자
"""
