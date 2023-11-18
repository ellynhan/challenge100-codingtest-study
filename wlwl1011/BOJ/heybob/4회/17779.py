import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

N = int(input())

arr = []

arr.append([0 for _ in range(N+1)])

for _ in range(N):
    arr.append([0] + list(map(int, input().split())))
ans = int(1e9)

for x in range(1,N+1):
    for y in range(1,N+1):
        for d1 in range(1, N+1):
            for d2 in range(1, N+1):
                if 1 <= x < x+d1+d2 <= N and 1 <= y-d1 < y < y+d2 <= N:
                    section = [[0 for _ in range(N+1)] for _ in range(N+1)]

                    #5번구역의 경계선을 표시한다
                    for i in range(d1+1):
                        section[x+i][y-i] = 5
                        section[x+d2+i][y+d2-i] = 5

                    for i in range(d2+1):
                        section[x+i][y+i] = 5
                        section[x+d1+i][y-d1+i] = 5    

                    #경계 내부도 채워준다.

                    for i in range(x+1,x+d1+d2):
                        flag = False
                        for j in range(1,N+1):   
                            if section[i][j] == 5:
                                flag = not flag
                            if flag:
                                section[i][j] = 5   
               
                    #5번 선거구에 포함되지 않은 구역 (r, c)의 선거구 번호를 채워준다
                    for r in range(1,N+1):
                        for c in range(1,N+1):
                            
                            if section[r][c] == 5:
                                continue
                            #1번 선거구: 1 ≤ r < x+d1, 1 ≤ c ≤ y   
                            elif 1 <= r < x+d1 and 1 <= c <= y:  
                                section[r][c] = 1               
                            #2번 선거구: 1 ≤ r ≤ x+d2, y < c ≤ N    
                            elif 1 <= r <= x+d2 and y < c <= N:  
                                section[r][c] = 2 
                            #3번 선거구: x+d1 ≤ r ≤ N, 1 ≤ c < y-d1+d2    
                            elif x+d1 <= r <= N and 1 <= c < y-d1+d2:
                                section[r][c] = 3
                            elif x+d2 < r <= N and y-d1+d2 <= c <= N:       
                                section[r][c] = 4        
                    section_sum = [0] * 5

                    for r in range(1,N+1):
                        for c in range(1,N+1):
                            section_sum[section[r][c]-1] += arr[r][c]
                    ans = min(ans, max(section_sum) - min(section_sum))


print(ans)