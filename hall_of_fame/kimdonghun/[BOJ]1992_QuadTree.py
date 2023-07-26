import sys

N = int(sys.stdin.readline())
quad_l = []

for i in range(N):
    quad_l.append(list(sys.stdin.readline()[:-1]))

def solution(N,r,c):
    global quad_l

    image_num = 0

    for i in range(r, r + N):
        for j in range(c, c + N):
            image_num += int(quad_l[i][j]) - 0

    if image_num == 0:
        print('0', end="")
    elif image_num == N * N:
        print('1', end="")
    else:
        print('(', end="")

        solution(N // 2, r, c)
        solution(N // 2, r, c + N//2)
        solution(N // 2, r + N//2, c)
        solution(N // 2, r + N//2, c + N//2)

        print(')', end="")

#print(quad_l)
solution(N, 0, 0)
