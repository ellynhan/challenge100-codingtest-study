import sys

N, M = map(int, sys.stdin.readline().split())
card_list = list(map(int, sys.stdin.readline().split()))
min_gap = 100000000

for i in range(N):
    for j in range(N):
        for k in range(N):
            if i != j and i != k and j != k:
                cur_sum = card_list[i] + card_list[j] + card_list[k]
                
                if(cur_sum <= M):
                    if(abs(M - cur_sum) < min_gap) : 
                        #print(abs(M - cur_sum), cur_sum)
                        min_gap = abs(M - cur_sum)
                        min_sum = cur_sum

print(min_sum)