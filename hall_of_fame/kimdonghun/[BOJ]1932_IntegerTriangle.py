import sys

N = int(sys.stdin.readline())
triangle =[]

for i in range(N):
    triangle.append(list(map(int, sys.stdin.readline().split())))

for i in range(1, N):
    for j in range(len(triangle[i])):
        if j == 0:
            triangle[i][j] = triangle[i-1][j] + triangle[i][j] 
        elif j > 0 and j < len(triangle[i]) - 1:
            triangle[i][j] = max(triangle[i-1][j], triangle[i-1][j-1]) + triangle[i][j]
        else:
            triangle[i][j] = triangle[i-1][j-1] + triangle[i][j] 

#print(triangle)
print(max(triangle[-1]))
