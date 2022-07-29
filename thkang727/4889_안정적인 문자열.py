#
#   문자열 실버1
#   4889
#


cnt=1
while(True):

    arr = input()
    cl_cnt, op_cnt,ans = 0,0,0
    
    if '-' in arr:
        break
    
    for j in range(len(arr)):
        if arr[j]=='}':
            if op_cnt<=0:
                ans+=1
                op_cnt+=1
            else:
                op_cnt-=1
        elif arr[j]=='{':
            op_cnt+=1
    
    print("{}. {}".format(cnt, (ans+(op_cnt+1)//2)))
    
    cnt+=1
        
        
