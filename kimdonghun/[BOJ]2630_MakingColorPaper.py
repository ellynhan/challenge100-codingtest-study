import sys

N = int(sys.stdin.readline())
paper_l = []
for i in range(N):
    paper_l.append(list(sys.stdin.readline().split()))

#print(paper_l)

one_cnt = 0
zero_cnt = 0

def solution(N, r, c):
    global one_cnt, zero_cnt

    cur_num = paper_l[r][c]

    for i in range(r, r + N):
        for j in range(c, c + N):
            if paper_l[i][j] != cur_num:
                divTwo = N // 2

                solution(divTwo, r, c)
                solution(divTwo, r, c + divTwo)
                solution(divTwo, r + divTwo, c)
                solution(divTwo, r + divTwo, c + divTwo)

                return
    
    if cur_num == '1':
        one_cnt += 1
    elif cur_num == '0':
        zero_cnt += 1

    return

solution(N, 0, 0)
print(zero_cnt)
print(one_cnt)
