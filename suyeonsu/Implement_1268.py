n = int(input())
info = [list(map(int, input().split())) for _ in range(n)]
cnt = [set() for _ in range(n)]

for stu in range(n):
    for grade in range(5):
        for i in range(n):
            if i != stu and info[i][grade] == info[stu][grade]:
                cnt[stu].add(i)

answer = 0
max_v = -1
for stu, x in enumerate(cnt, start=1):
    if max_v < len(x):
        max_v = len(x)
        answer = stu
print(answer)
