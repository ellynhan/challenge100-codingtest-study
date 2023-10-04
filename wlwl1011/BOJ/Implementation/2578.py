import sys
input = lambda : sys.stdin.readline().rstrip('\r\n')

arr = []
visited = [[0 for _ in range(5)] for _ in range(5)]
for _ in range(5):
    arr.append(list(map(int, input().split())))
ans = 0
flag = False
s = []
for _ in range(5):  
    s.append(list(map(int, input().split())))

for index_i in range(5):
    for index_j in range(5):
        index = s[index_i][index_j]
    
        
        check = 0
        ans += 1
        for i in range(5):
            for j in range(5):
                if arr[i][j] == index:
                    visited[i][j] = 1
                    break
        left = 0 
        right = 0
        for i in range(5):
            
            if visited[i][i] == 1:
                left += 1

            if left == 5:
                check += 1

            if visited[i][4-i] == 1:
                right += 1

            if right == 5:
                check += 1    

            #세로 체크       
            cnt = 0
            for j in range(5):
                if visited[i][j]:
                    cnt += 1
            if cnt == 5:
                check += 1
                 
            cnt2 = 0        
            for j in range(5):
                if visited[j][i]:
                    cnt2 +=1

            if cnt2 == 5:
                check += 1
        if check >=3 :
            print(ans)
            flag = True
            break        
    if flag:
        break








        
        

