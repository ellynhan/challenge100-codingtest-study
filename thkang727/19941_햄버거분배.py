#
#   19941 햄버거분배
#   그리디 실버3
# #

import sys
input = sys.stdin.readline

n, k = map(int,input().split())

arr = list(input())

cnt = 0

# list 길이 n
for i in range(n):
    if arr[i] =="P":
      # k 범위 내에서만 H 있는지 확인
        for j in range(i-k,i+k+1):
          #0보다 크고 n 보다 작은 k
            if 0<=j and j<n and arr[j] =="H":
                cnt +=1
                # 재검출되는것을 방지하기 위해 아무문자로 변경
                arr[j] ="XX"
                break
print(cnt)

