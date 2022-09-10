#
#   1011   Fly me to the Alpha Centauri
#   수학 골드5
# #

import sys

input = sys.stdin.readline


s = input()

suf = []
for i in range(len(s)):
    suf.append(s[i:])

suf.sort()
for i in suf:
    print(i)
