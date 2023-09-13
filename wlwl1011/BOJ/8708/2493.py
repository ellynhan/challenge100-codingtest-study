# import sys, os, io, atexit
# input = lambda : sys.stdin.readline().rstrip('\r\n')
# stdout = io.BytesIO()
# sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
# atexit.register(lambda: os.write(1, stdout.getvalue()))

N = int(input())
arr = list(map(int, input().split()))

max_height = max(arr)
max_height_idx = arr.index(max_height)
answer = [0] * N


#맨 뒤에서 부터 가장 높은 높이까지
for i in range(N-1,-1,-1):

    if arr[i] < arr[i-1]:
        answer[i]= i
    else:
        temp = []
        if i == max_height_idx or i == 0:
            answer[i] = 0
        elif i > max_height_idx:
            temp = arr[max_height_idx:i]
            
            start = 0
            end = len(temp)-1
            
        else:
            temp = arr[i:max_height_idx]
            
            start = 0
            end = len(temp)-1
        temp.sort()    
        
        while start <= end:
            mid = ( start + end ) // 2    
            if mid >= len(temp):
                break
            if temp[mid] >=  arr[i]:
                end = mid - 1
                answer[i] = arr.index(temp[mid])+1
                #print('binary search',temp[mid])
            else:
                start = mid + 1    

print(*answer)