n, m = map(int, input().split())
graph1 = []
graph2 = []
count = 0

def convertgraph(i, j):		
    for x in range(i, i + 3):
        for y in range(j, j + 3):
            graph1[x][y] = 1 - graph1[x][y]


for i in range(n):				
    graph1.append(list(map(int, input())))

for i in range(n):				
    graph2.append(list(map(int, input())))

for i in range(n - 2):
    for j in range(m - 2):
        if graph1[i][j] != graph2[i][j]: 
            convertgraph(i, j)			
            count += 1				 	
flag = 0							

for i in range(n):					
    for j in range(m):
        if graph1[i][j] != graph2[i][j]:
            flag = 1
            break

if flag == 1:					 -1
    print(count)
