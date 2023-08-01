N = int(input())
times = list(map(int, input().split(" ")))
times.sort()
answer = 0
for i, time in enumerate(times):
    answer+= (N-i)*time
print(answer)