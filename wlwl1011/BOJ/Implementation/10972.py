N = int(input())
a = list(map(int, input().split()))

for i in range(N-1, 0, -1):
    if a[i] > a[i-1]:
        x = i-1
        for j in range(N-1, 0, -1):
            if a[j] > a[x]:
                
                a[j], a[x] = a[x], a[j]
                #: 기준의 값을 교환하고 다시 기준의 오른쪽 원소들을 정렬하는 작업 중에 
                # index에 주의한다.
                a = a[:i] + sorted(a[i:])
                print(*a)
                exit(0)
print(-1)

