import sys

N = int(sys.stdin.readline())
n_list = []

n_list = list(map(int, sys.stdin.readline().split()))

c_list = set(n_list)
c_list = sorted(list(c_list))

#print(c_list)
c_dict = {c_list[i] : i for i in range(len(c_list))}
#print(c_dict)

for i in n_list:
    print(c_dict[i], end = " ")