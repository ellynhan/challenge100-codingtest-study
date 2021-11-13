#백준 1015번 수열 정렬
#실버 4

N = int(input())
A = list(map(int, input().split()))
ans = [-1 for _ in range(N)]
count = 0
for i in range(max(A)+1):
    j = 0
    while j < N:
        if A[j] == i:
            ans[j] = count
            count +=1
        j+=1
print(' '.join(map(str, ans)))
