n, k = map(int, input().split())
coin = []

for _ in range(n):
    temp = int(input())
    
    coin.append(temp)
    
coin.sort(reverse=True)

num = 0
cnt = 0
for i in coin:
    cnt += k//i
    k -= (k//i * i)
    
    if k <= 1:
        break;

print(cnt)