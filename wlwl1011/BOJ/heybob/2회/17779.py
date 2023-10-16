import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

N = int(input())

arr = []
arr.append([0]*(N+1))

for _ in range(N):
    arr.append([0] + list(map(int, input().split())))

value = []
ans = int(1e9)
for x in range(1, N+1):
    for y in range(1, N+1):
        for d1 in range(1, N+1):
            for d2 in range(1, N+1):
                if 1 <= x < x+d1+d2 <= N and 1 <= y-d1 < y < y+d2 <= N:
                    value.append((x,y,d1,d2))

for x, y, d1, d2 in value:
    section = [[0 for _ in range(N+1)] for _ in range(N+1)] #구역을 기록한다.
    arr_sum = [0]*5 #구역 5가지 각각의 합을 구한다.

    for i in range(d1+1):
       #(x, y), (x+1, y-1), ..., (x+d1, y-d1)
       section[x+i][y-i] = 5
       #(x+d2, y+d2), (x+d2+1, y+d2-1), ..., (x+d2+d1, y+d2-d1)
       section[x+d2+i][y+d2-i] = 5  

    for i in range(d2+1):
        #(x, y), (x+1, y+1), ..., (x+d2, y+d2)
        section[x+i][y+i] = 5
        #(x+d1, y-d1), (x+d1+1, y-d1+1), ... (x+d1+d2, y-d1+d2)
        section[x+d1+i][y-d1+i] = 5    

   
    #5 안에 구역 색칠하러 갑니다.
    for i in range(x+1, x+d1+d2):
        flag = False
        for j in range(1, N+1):
            if section[i][j] == 5:
                flag = not flag
            if flag:
                section[i][j] = 5
    
    for r in range(1, N+1):
        for c in range(1, N+1): 
            if section[r][c] == 5:
                continue
            elif 1 <= r < x+d1 and 1 <= c <= y:
                section[r][c] = 1
            elif 1 <= r <= x+d2 and y < c <= N:
                section[r][c] = 2
            elif x+d1 <= r <= N and 1 <= c < y-d1+d2:
                section[r][c] = 3
            elif x+d2 < r <= N and y-d1+d2 <= c <= N:
                section[r][c] = 4
        

    for r in range(1, N+1):
        for c in range(1, N+1):
            arr_sum[section[r][c]-1] += arr[r][c] 
    ans = min(ans,max(arr_sum)-min(arr_sum))

print(ans)                             


