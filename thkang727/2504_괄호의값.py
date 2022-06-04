#
#   2504
#   괄호의 값
#   구현 실버1
# #

import sys

input = sys.stdin.readline
arr = list(input())
arr.pop()

stack = []
tmp, ans = 1, 0

for i in range(len(arr)):
    if arr[i] =='(':
        stack.append(arr[i])
        tmp*=2
    elif arr[i] =='[':
        stack.append(arr[i])
        tmp*=3
    elif arr[i] ==')':
        if not len(stack)>0 or stack[-1] == "[":
            ans =0
            break
        if arr[i-1] == "(":
            ans += tmp
        stack.pop()
        tmp //=2
    else:
        if not len(stack)>0 or stack[-1]=="(":
            ans=0
            break
        if arr[i-1] == "[":
            ans += tmp
        stack.pop()
        tmp //=3

if len(stack)>0:
    print(0)
else:
    print(ans)
