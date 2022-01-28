import sys

input_N = sys.stdin.readline()
input_N = list(input_N)
input_N.sort()

while input_N :
    print(input_N.pop(), end='')
