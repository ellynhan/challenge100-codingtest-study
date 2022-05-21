import sys

N = int(sys.stdin.readline())
paper_l = []
for i in range(N):
    paper_l.append(list(sys.stdin.readline().split()))

one_cnt = 0
zero_cnt = 0
minusone_cnt = 0

def solution(N, r, c):
    global one_cnt, zero_cnt, minusone_cnt

    cur_num = paper_l[r][c]

    for i in range(r, r + N):
        for j in range(c, c + N):
            if paper_l[i][j] != cur_num:      
                divThree = N // 3

                solution(divThree, r, c)
                solution(divThree, r, c + divThree * 1)
                solution(divThree, r, c + divThree * 2)

                solution(divThree, r + divThree * 1, c)
                solution(divThree, r + divThree * 1, c + divThree * 1)
                solution(divThree, r + divThree * 1, c + divThree * 2)

                solution(divThree, r + divThree * 2, c)
                solution(divThree, r + divThree * 2, c + divThree * 1)
                solution(divThree, r + divThree * 2, c + divThree * 2)

                return

    if cur_num == '-1' :
        minusone_cnt += 1
    elif cur_num == '0' :
        zero_cnt += 1
    elif cur_num == '1' :
        one_cnt += 1
    return 
    
#print(paper_l)
solution(N, 0,0)

print(minusone_cnt)
print(zero_cnt)
print(one_cnt)
