from collections import Set
import sys

n = sys.stdin.readline().rstrip()
inputSet = set(sys.stdin.readline().rstrip().split())

n = sys.stdin.readline().rstrip()
answer = sys.stdin.readline().rstrip().split()
for iter in answer :
    if iter in inputSet:
        print(1)
    else :
        print(0)