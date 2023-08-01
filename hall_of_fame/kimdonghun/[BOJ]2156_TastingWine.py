import sys

N = int(sys.stdin.readline())

n_list = [0] * 10001

for i in range(N):
    n_list[i] = int(sys.stdin.readline())

d = [0] * 10001

d[0] = n_list[0]
d[1] = n_list[0] + n_list[1]

for i in range(2, N):
    d[i] = max(d[i-3] + n_list[i-1] + n_list[i], d[i-2] + n_list[i], d[i-1]) 
#print(n_list)
#print(d)
print(d[N-1])
