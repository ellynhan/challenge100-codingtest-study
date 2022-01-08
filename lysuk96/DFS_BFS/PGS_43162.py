#네트워크
from collections import defaultdict

def solution(n, computers):
    count = 1
    
    def dfs(x):
        computers[x][x] = count
        for i in range(0, n):
            if (computers[x][i]==1 and computers[i][i]==1):
                dfs(i)
        

    for i in range(n):
        if computers[i][i] == 1:
            # print(computers)
            count+=1
            dfs(i)

    print(computers)
    # print(count)
    answer = count-1
    return answer

n = 4
computers = [[1,0,1,0],[0,1,0,0],[1,1,1,1],[0,0,1,1]]	
print(solution(n, computers))