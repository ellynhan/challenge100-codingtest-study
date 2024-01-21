def makeRectangle(rectangle):
    frame = [[-1] * 102 for _ in range(102)]
    for r in rectangle:
        x1,x2,y1,y2=2*r[0], 2*r[2],2*r[1], 2*r[3]
        for x in range(x1,x2+1):
            for y in range(y1,y2+1):
                if(x1<x<x2 and y1<y<y2):
                    frame[y][x]=0
                elif(frame[y][x]!=0):
                    frame[y][x]=1
    return frame
def dfs(visit,frame,character,item,cnt):
    global answer
    dx=[0,1,-1,0]
    dy=[1,0,0,-1]
    if(character[0]==item[0] and character[1]==item[1]):
        if(answer>cnt):
            answer=cnt
            return
    for i in range(4):
        x=character[0]+dx[i]
        y=character[1]+dy[i]
        if(frame[y][x]==1 and visit[y][x]==1):
            visit[y][x]=0
            dfs(visit,frame,[x,y],item,cnt+1)
            visit[y][x]=1
def solution(rectangle, characterX, characterY, itemX, itemY):
    global answer
    answer=3000
    frame=makeRectangle(rectangle)
    characterX, characterY, itemX, itemY=2*characterX, 2*characterY, 2*itemX, 2*itemY
    frame[characterY][characterX]=1
    visit = [[1 for _ in range(102)] for _ in range(102)]
    dfs(visit,frame,[characterX, characterY],[itemX, itemY],0)
    return answer//2
