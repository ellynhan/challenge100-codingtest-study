import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

N = int(input())
arr = [[0 for _ in range(N+1)] for _ in range(N+1)]
ans = int(1e9)
for i in range(N):
    temp = list(map(int, input().split()))
    arr[i+1][1:] = temp

#선거구 나누기

#d1, d2 ≥ 1, 1 ≤ x < x+d1+d2 ≤ N, 1 ≤ y-d1 < y < y+d2 ≤ N

value = []

for x in range(1,N+1):
    for y in range(1,N+1):
        for d1 in range(1,N+1):
            for d2 in range(1,N+1):
                if x < x + d1 + d2 <= N and 1 <= y - d1 < y < y + d2 <=N:
                    value.append([x, y, d1, d2])



for x, y, d1, d2 in value:
    #print(x,y,d1,d2)
    section = [[0 for _ in range(N+1)] for _ in range(N+1)]
    sum = [0 for _ in range(5)]
    for i in range(d1+1):
        section[x+i][y-i] = 5 
        section[x+d2+i][y+d2-i] = 5
    for j in range(d2+1):
        section[x+j][y+j] = 5
        section[x+d1+j][y-d1+j] = 5 
    

    for i in range(x+1, x+d1+d2):
        flag = False
        for j in range(1,N+1):
            if section[i][j] == 5:
                flag = not flag
            if flag:
                section[i][j] = 5
   
    #안은 어떻게 칠하지?  

    for r in range(1,N+1):
        for c in range(1,N+1):
            if section[r][c] == 5:
                continue
            if 1 <= r < x + d1 and 1 <= c <= y:
                section[r][c] = 1
            elif  1 <= r <= x + d2 and y < c <= N:   
                section[r][c] = 2  
            elif x + d1  <= r <= N and 1 <= c < y - d1 + d2 :
                section[r][c] = 3
            elif x + d2 < r <= N and y - d1 + d2 <= c <= N:
                section[r][c] = 4
            else:
                section[r][c] = 5

    

    for r in range(1,N+1):
        for c in range(1,N+1):   
            sum[section[r][c]-1] += arr[r][c]                 
    # print("sum : ",sum , "diff : ", max(sum) - min(sum))
    # print(x,y,d1,d2)
    # print(sum)
    ans = min( ans, max(sum) - min(sum) )  
               
           


print(ans)