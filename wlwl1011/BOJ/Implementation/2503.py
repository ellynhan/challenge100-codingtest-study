from itertools import permutations
N = int(input())

data = ['1', '2', '3', '4', '5', '6', '7', '8', '9']
num = list(permutations(data, 3))

for _ in range(N):
    n, s, b = map(int, input().split())
    n = list(str(n))
    rmcnt = 0
    for i in range(len(num)):
        strike = ball = 0
        i -= rmcnt # num[0] 부터 시작
        for j in range(3):
            if num[i][j] == n[j]:
                strike += 1
            elif n[j] in num[i]:
                ball += 1
            
        if (strike != s) or (ball != b):
            num.remove(num[i])
            rmcnt += 1

print(len(num))