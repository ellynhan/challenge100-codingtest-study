import sys

N = int(sys.stdin.readline())

isHanNum = [True] * 10000


def judge_han_num(num):
    tmpNum = num

    if(num < 100) :
        return
    
    curSeqNum = tmpNum % 10
    preSeqNum = (tmpNum // 10) % 10

    curDiff = curSeqNum - preSeqNum
    preDiff = curDiff

    tmpNum //= 10


    while tmpNum >= 10 :
        #print(curSeqNum)

        curSeqNum = tmpNum % 10
        preSeqNum = (tmpNum // 10) % 10

        curDiff = curSeqNum - preSeqNum

        if curDiff != preDiff :
            isHanNum[num] = False

        preDiff = curDiff

        tmpNum //= 10


for i in range (1, N+1) :
    judge_han_num(i)

count_han = 0

for i in range (1, N+1) :
    if isHanNum[i] :
        #print(i)
        count_han += 1

print(count_han)