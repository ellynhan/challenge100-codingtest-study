import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

#바로 옆에 다른 색깔의 볼이 있으면 그 볼을 모두 뛰어 넘어 옮길 수 있다

#옮길 수 있는 볼의 색깔은 한 가지이다. 즉, 빨간색 볼을 처음에 옮겼으면 다음에도 빨간색 볼만 옮길 수 있다

def compare(arr,ball):
    count = 0
    copy_arr = arr[:]
    index = 0
    for i in range(N-1,-1,-1):
        if copy_arr[i] == ball:
            copy_arr = copy_arr[:i]
        else:
            index = i
            break    
        #print(arr)    
    for i in range(index-1,-1,-1):
        if copy_arr[i] == ball:
            count += 1      
    return count   


N = int(input())
arr = input()

print(min(compare(arr,'R'),compare(arr,'B')))