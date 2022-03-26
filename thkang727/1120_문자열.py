#
#   17413
#   문자열 실버3
# #

from sys import stdin

a,b = stdin.readline().rstrip().split()

result = []
for i in range(len(b) - len(a) + 1):
    cnt = 0
    for j in range(len(a)):
        if a[j] != b[i + j]:
            cnt += 1
    result.append(cnt)

print(min(result))
