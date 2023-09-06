# import sys, os, io, atexit
# input = lambda : sys.stdin.readline().rstrip('\r\n')
# stdout = io.BytesIO()
# sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
# atexit.register(lambda : os.write(1, stdout.getvalue()))

arr = list(input())

start = 0
end = len(arr)-1

if arr[start] == arr[end]: #처음 양 싸이클이 같은 경우
    start += 1
    end -= 1
else:
    end -= 1
count = 0    
while start <= end:
    print(arr)
    if arr[start] == 'a':
        start += 1
    else: #만약 b 면은 뒤에 있는 a랑 바꾸자
        if arr[end] == 'b':    
            arr[start], arr[end] = arr[end], arr[start]
        else:
            while True:
                if arr[end] == 'b':
                    break
                end -= 1 #앞으로 한칸 땡겨오그레이  
            arr[start], arr[end] = arr[end], arr[start]    
    count += 1
print(count)    