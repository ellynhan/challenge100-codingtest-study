import sys

n = int(sys.stdin.readline())
data = []

for i in range(n) :
    input_str = sys.stdin.readline().strip()
    if not input_str in data :
        data.append(input_str)

data.sort()
data.sort(key=lambda x: len(x))

for i in data :
    print(i)
