import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

def compress(start_x, start_y, n):
    if n > 0:
        
        check = arr[start_x][start_y]
        flag = True
        for i in range(n):
            for j in range(n):
                if arr[start_x+i][start_y+j] != check:
                    flag = False
                    break
        if flag == True:
            
            print(check,end='')
        else:
            print('(',end='')
            compress(start_x, start_y, n//2)  
            compress(start_x, start_y+n//2, n//2)  
            compress(start_x+n//2, start_y, n//2)  
            compress(start_x+n//2, start_y+n//2, n//2)  
            print(')',end='')    


N = int(input())
arr = []
for _ in range(N):
    arr.append(list(map(int, input())))


compress(0, 0, N)