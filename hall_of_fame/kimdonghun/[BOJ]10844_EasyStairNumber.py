import sys

N = int(sys.stdin.readline())

n_list = [[0 for _ in range(10)] for _ in range(101)]
for i in range(1, 10):
    n_list[0][i] = 1

for i in range(0, N):
    for j in range(0, 10):
        if j-1 >= 0 :
            n_list[i+1][j-1] = n_list[i+1][j-1] + n_list[i][j] % 1000000000
            #print("pre", i, j-1)
        if j+1 <= 9 :
            n_list[i+1][j+1] += n_list[i+1][j+1] + n_list[i][j] % 1000000000
            #print("after", i, j+1)
        
#print(n_list)
print(sum(n_list[N-1]) % 1000000000)
