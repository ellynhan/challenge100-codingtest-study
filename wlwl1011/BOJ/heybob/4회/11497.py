T = int(input())

for _ in range(T):
    N = int(input())
    arr = list(map(int, input().split()))
    answer = 0
    arr.sort()
    for i in range(N-2):
        answer = max(answer, arr[i+2]-arr[i])
    print(answer)