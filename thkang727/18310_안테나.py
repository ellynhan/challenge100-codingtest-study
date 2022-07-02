#
#   그리디 실버3
#   18310
#


from sys import stdin

n = int(stdin.readline())


arr = list(map(int, stdin.readline().split()))
arr = sorted(arr)
print(arr[(n-1)//2])
