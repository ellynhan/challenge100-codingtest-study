n = input()

nLen = len(n)
n = int(n)
ans = 0
for i in range(1, nLen):
    ans += i * 9 * 10**(i-1)
    
ans += nLen * (n - 10**(nLen-1) + 1)
print(ans)
