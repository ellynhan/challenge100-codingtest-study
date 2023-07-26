
isSelfNum = [True] * 10000

def makingNum(num):
    curSeqNum = 0
    tmpNum = num

    curSeqNum += tmpNum

    while tmpNum > 0 :
        #print(curSeqNum)
        curSeqNum += tmpNum % 10
        tmpNum //= 10

    #print(curSeqNum)
    if(curSeqNum < 10000) :
        isSelfNum[curSeqNum] = False

for i in range (10000) :
    makingNum(i)

for i in range (10000) :
    if isSelfNum[i] :
        print(i)
