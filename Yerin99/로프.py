import sys

n = int(input())  # 로프 개수
max_weight = []
candidate = []
ans = []

for i in range(n):
    max_weight.append(int(sys.stdin.readline()))

max_weight.sort(reverse=True)

for i in range(n):
    candidate.append(max_weight[i])
    ans.append(max_weight[i]*(i+1))

print(max(ans))
