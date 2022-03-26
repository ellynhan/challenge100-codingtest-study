#
#   2851!
#   브루투포스 브론즈1
# #


import sys


ans = 0

input = sys.stdin.readline



for i in range(10):
    
    mushroom = int(input())
    ans += mushroom
    if ans==100:
        print(ans)
        break
    elif ans >100 or i ==9:
        if (ans-100)**2 > (100-(ans-mushroom))**2:
            print((ans-mushroom))
            break
        else:
            print(ans)
            break

