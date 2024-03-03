count = 0

def isOk(arr,n):
 
    for i in range(n):
        if arr[i] == arr[n]:
  
            return False
        if abs(n - i) == abs(arr[n]-arr[i]):
   
            return False
    return True    

def nQueen(arr,n):
 
    global count 
    if n == N:
        count += 1
        return
    for i in range(N):
        arr[n] = i
       
        if isOk(arr,n):
           
            nQueen(arr,n+1)
        arr[n] = 0    
           

N = int(input())
arr = [-1 for _ in range(N)]

nQueen(arr,0)
print(count)
