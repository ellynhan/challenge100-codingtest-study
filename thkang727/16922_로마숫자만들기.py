#
#   16922   로마 숫자 만들기
#   수학 실버3
# #

#  I, V, X, L = 1, 5, 10, 50
# 중복조합

import sys

from itertools import combinations_with_replacement

input = sys.stdin.readline

dataset = [1,5,10,50]

n = int(input())

tmp = list(combinations_with_replacement(dataset, n))
ans = []
for i in tmp:
    ans.append(sum(i))
print(len(set(ans)))
