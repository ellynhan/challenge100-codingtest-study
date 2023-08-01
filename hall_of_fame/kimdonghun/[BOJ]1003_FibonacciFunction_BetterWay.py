import sys

d_list_zero = [1,0,1]
d_list_one = [0,1,1]

def fibonacchi(x):
    length = len(d_list_zero)
    if x >= length:
        for i in range(length, x+1):
            d_list_zero.append(d_list_zero[i-1] + d_list_zero[i-2])
            d_list_one.append(d_list_one[i-1] + d_list_one[i-2])

T = int(sys.stdin.readline())

for i in range(T):

    N = int(sys.stdin.readline())
    fibonacchi(N)
    print(d_list_zero[N], d_list_one[N])
