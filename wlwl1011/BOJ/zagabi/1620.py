import sys

input = lambda: sys.stdin.readline().rstrip('\r\n')

N, M = map(int, input().split())

name_to_number = {}
number_to_name = {}

for i in range(1, N+1):
    name = input()
    name_to_number[name] = i
    number_to_name[i] = name

for _ in range(M):
    query = input()
    if query.isdigit():
        print(number_to_name[int(query)])
    else:
        print(name_to_number[query])
