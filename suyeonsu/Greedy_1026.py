n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

A.sort(reverse=True)
B.sort()
answer = 0
for a, b in zip(A, B):
    answer += a*b
print(answer)
