n,m = map(int,input().split())
board =[]
minValue = n*m

for i in range(n):
    tmp = input()
    board.append(tmp)

line = ["WBWBWBWB","BWBWBWBW"]
twoType = [["WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW"],
           ["BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB"]]

def checkBoard(y,x,minValue):
    for i in range(2):
        if board[y:8][x:8] == twoType[i]:
            return 0
        else:
            sum = 0
            for yy in range(y,y+8):
                for xx in range(x,x+8):
                    if board[yy][xx]!=twoType[i][yy-y][xx-x]:
                        sum += 1
            minValue = min(minValue, sum)
    return minValue

checkBoard(0,0,minValue)
for i in range(n-7):
    for j in range(m-7):
        minValue = min(minValue,checkBoard(i,j,minValue))


print(minValue)
