N = int(input())
arr = []

answer = 0
def dfs(number,visited):
    #print(number, visited)
    global answer
    if number == N:
        answer = max(answer, len(visited))
        return
    x1, x2 = arr[number]
    #print("얘 넣을까 말까", x1,x2)
    flag = True
    for r, c in visited:
        #print('얘 일단 들어있는데 얘랑 비교해보자', r,c)
        if x1 <= c:
            flag = False
            break
    if flag:
        #print("넣을게")
        visited.append((x1,x2))        
        dfs(number+1,visited)
        visited.pop()
        dfs(number+1,visited)
    else:   
        dfs(number+1,visited) 
        
        


for _ in range(N):
    arr.append(list(map(int, input().split())))
arr.sort()
dfs(0,[])
    


print(answer)