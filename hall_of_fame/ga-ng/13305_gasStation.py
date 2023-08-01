n = int(input())

far = list(map(int, input().split()))  ## 거리

cost = list(map(int, input().split()))  ## 기름 가격

mincost = cost[0]
sum = 0

for i in range(len(far)):
    
    if cost[i] < mincost:
        mincost = cost[i]
    
    sum += mincost * far[i]
    
print(sum)