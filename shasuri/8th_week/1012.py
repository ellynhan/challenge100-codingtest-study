def dfs(xCoord, yCoord):
    if xCoord > xSize - 1 or xCoord < 0:
        return 0
    if yCoord > ySize - 1 or yCoord < 0:
        return 0

    lettceExist = lettuceFarm[yCoord][xCoord]

    if lettceExist == 1:
        lettuceFarm[yCoord][xCoord] = 0
        return dfs(xCoord+1, yCoord) + dfs(xCoord-1, yCoord) + dfs(xCoord, yCoord+1) + dfs(xCoord, yCoord-1) + 1

    if lettceExist == 0:
        return 0


def checkLettuce(xSize, ySize):
    checkedLettuce = 0
    worm = 0

    for y in range(ySize):
        for x in range(xSize):
            checkedArea = dfs(x, y)
            checkedLettuce += dfs(x, y)

            if checkedArea > 0:
                worm += 1
                #print(f"worm ++, in ({x},{y}).")
            if checkedLettuce >= lettuceNum:
                return worm

    return worm


if __name__ == "__main__":
    testCase = int(input())

    for caseIndex in range(testCase):
        wormNum = None
        mnkInput = list(map(int, input().split()))

        xSize = mnkInput[0]
        ySize = mnkInput[1]
        lettuceNum = mnkInput[2]

        lettuceFarm = [[0 for xs in range(xSize)] for ys in range(ySize)]

        for lettuceIndex in range(lettuceNum):
            xyInput = list(map(int, input().split()))
            xCoord = xyInput[0]
            yCoord = xyInput[1]

            lettuceFarm[yCoord][xCoord] = 1

        wormNum = checkLettuce(xSize, ySize)
        print(wormNum)
