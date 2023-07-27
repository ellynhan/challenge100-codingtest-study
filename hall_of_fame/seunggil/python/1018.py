import sys

n = sys.stdin.readline().rstrip().split()

n = list(map(int,n))
inputData = []
for i in range(n[0]):
    inputData.append(list(sys.stdin.readline().rstrip()))

answer = 1 << 31 - 1
for i in range(n[0]-7):
    for j in range(n[1]-7):
        color = 'W'
        ans = [0,0]
        for a in range(i,i+8):
            for b in range(j,j+8):
                if inputData[a][b] == color:
                    ans[0] +=1
                if inputData[a][b] != color:
                    ans[1] +=1
                color = 'B' if color == 'W' else 'W'
            color = 'B' if color == 'W' else 'W'
        answer = min([answer,min(ans)])
print(answer)