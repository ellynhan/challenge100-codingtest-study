#
#   boj 10815
#   이진탐색.
# #


n = int(input())
num = list(map(int, input().split()))
m = int(input())
card = list(map(int, input().split()))
num.sort()

ans = [0] * m

for _ in range(m):
    left = 0
    right = len(num)-1
    while left <= right:
        mid = (left + right)//2
        if card[_] == num[mid]:
            ans[_] = 1
            break
        if left > right:
            break
        elif card[_] > num[mid]:
            left = mid +1
        else :
            right = mid - 1

for j in ans:
    print(j, end=' ')

