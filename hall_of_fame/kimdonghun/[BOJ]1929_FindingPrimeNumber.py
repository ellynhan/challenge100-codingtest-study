import sys

M, N = map(int, sys.stdin.readline().split())
plist = [True for i in range(N+1)]

#print(plist)

plist[1] = False
for cur_num in range(2, N+1) :

    mul_num = cur_num
    i = 2

    while mul_num <= N :
        mul_num = cur_num * i

        if(mul_num > N) :
            break

        plist[mul_num] = False
        i += 1

for i in range(M, len(plist)) :
    if plist[i] == True:
        print(i)