def compress(x, y, n):
    global answer
    if n ==1:
        answer +=vids[x][y]
        return

    flag = False
    now = vids[x][y]
    for i in range(x,x+n):
        for j in range(y, y+n):
            if vids[i][j]!=now:
                flag = True
                break
    if flag:
        new_n = n//2
        answer+='('
        compress(x,y,new_n)
        compress(x,y+new_n,new_n)
        compress(x+new_n,y,new_n)
        compress(x+new_n,y+new_n,new_n)
        answer+=')'
    else:
        answer +=now
        return



N = int(input())
answer = ''

vids = [list(input()) for _ in range(N)]
# print(vids)
compress(0, 0, N)
print(answer)