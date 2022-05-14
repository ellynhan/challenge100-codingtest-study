#
#   1746    
#   구현 실버3
# #
import sys
input = sys.stdin.readline

n = int(input())

len_n = len(str(n))
cnt=0

for i in range(len_n-1):
    cnt += 9*10**i*(i+1)

print(cnt + (n-10**(len_n-1)+1)*len_n)
