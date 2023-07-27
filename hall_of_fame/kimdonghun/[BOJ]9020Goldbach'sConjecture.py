import sys
import math

T = int(sys.stdin.readline())

max_num = 10000
plist = [True for i in range(max_num + 1)]
plist[0] = False
plist[1] = False

for i in range(2, int(math.sqrt(max_num)) + 1) :
    j = 2
    while i * j <= max_num:
        plist[i * j] = False
        j += 1


for k in range(T):
    N = int(sys.stdin.readline())

    a = N // 2
    b = N // 2

    for i in range(int(N/2)):
        if plist[a] == True and plist[b] == True:
            print(a, b)
            break
        else:
            a -= 1
            b += 1

    