import sys

input = sys.stdin.readline

num = list(map(int, input().rstrip()))

num.sort(reverse=True)

for i in num:
    print(i, end="")