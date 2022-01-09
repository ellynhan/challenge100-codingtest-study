# 브론즈 1

import sys

if __name__ == "__main__":
    numPhase1 = int(sys.stdin.readline()[:-1])

    phase1 = list(map(int, sys.stdin.readline()[:-1].split()))
    phase1.sort()
    pointer = 1
    for i in phase1:
        if ((len(phase1) == 1) & (phase1[0] == 1)):
            print(2)
            break
        if (len(phase1) == phase1[-1]):
            print(numPhase1 + 1)
            break
        if i != pointer:
            print(pointer)
            break
        pointer += 1

# 27분 
# 틀림 6 사유 : indention 제대로, 1만 예약 되었을때 고려, 꽊 찼을때 고려
