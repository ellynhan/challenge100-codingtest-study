import sys

data = []
n = int(input())
for _ in range(n):
    line = sys.stdin.readline().split()
    line_list = [line[0]]
    line_list.extend(sorted(list(map(int, line[1:]))))
    data.append(line_list)

data.sort(key=lambda x: str(x[0]))
data.sort(key=lambda x: (len(x), x[1:]), reverse=True)

for i in range(n):
    print(data[i][0])
