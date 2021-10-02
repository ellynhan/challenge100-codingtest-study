N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))


answer = [0 for _ in range(N)]
A = sorted(A)

B_tuple = []
for index, value in enumerate(B):
    B_tuple.append((index,value))
B_tuple = sorted(B_tuple, key=lambda x:x[1], reverse=True)

for el in B_tuple:
    answer[el[0]] = A.pop(0)

sum = 0

for i in range(N):
    sum += answer[i] * B[i]
print(sum)