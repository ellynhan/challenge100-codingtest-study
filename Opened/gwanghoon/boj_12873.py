import sys

def makeQueue(inputQueue,queueLen):
    for i in range(queueLen):
        inputQueue.append(i+1)

def gameStart(gameQueue):
    pointer = 1
    stage = 1
    for i in range(len(gameQueue) - 1):
        pointer = (pointer + stage**3 - 1) % (len(gameQueue))
        if (pointer == 0):
            pointer = len(gameQueue)
        del gameQueue[pointer-1]
        pointer = pointer % (len(gameQueue))
        if (pointer > len(gameQueue)):
            pointer = len(gameQueue)
        stage += 1
    print(gameQueue[0])

if __name__ == "__main__":
    queueLen = int(sys.stdin.readline()[:-1])
    gameQueue = []
    makeQueue(gameQueue, queueLen)
    gameStart(gameQueue)

# solved domain : circular queue
# time consumed : 1:24:30
# incorrect count : 2
# time over : 0
# note : del 함수는 인덱스를 기점으로 삭제를 한다, 문제를 잘 읽고 풀도록 하자