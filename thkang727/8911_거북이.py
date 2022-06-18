#
#   8911
#   거북이
#   구현 실버2
# #



import sys

input = sys.stdin.readline


n = int(input())

for i in range(n):
    arr_n = input()
    #x==True, y == False
    xory=False
    #up==True, down == False
    upordown=True
    x,y=0,0
    min_x,min_y,big_x,big_y=0,0,0,0
    for j in range(len(arr_n)):
        #print(arr_n[j], end=' ')
        if xory == True:
            if arr_n[j]=='F':
                if upordown==True:
                    x+=1
                else:
                    x-=1
            elif arr_n[j]=='B':
                if upordown==True:
                    x-=1
                else:
                    x+=1
            elif arr_n[j]=='L':
                xory = not( xory)
            elif arr_n[j]=='R':
                xory = not(xory)
                upordown = not(upordown)
        else:
            if arr_n[j]=='F':
                if upordown==True:
                    y+=1
                else:
                    y-=1
            elif arr_n[j]=='B':
                if upordown==True:
                    y-=1
                else:
                    y+=1
            elif arr_n[j]=='L':
                xory = not(xory)
                upordown=not(upordown)
            elif arr_n[j]=='R':
                xory = not(xory)
        #print(x,y)
        if x<0:
            if abs(min_x) < abs(x):
                min_x=x
        elif x>0:
            if big_x < x:
                big_x=x
        if y<0:
            if abs(min_y ) < abs(y):
                min_y=y
        elif y>0:
            if big_y <y:
                big_y=y
    print((abs(min_x)+big_x)*(abs(min_y)+big_y))
