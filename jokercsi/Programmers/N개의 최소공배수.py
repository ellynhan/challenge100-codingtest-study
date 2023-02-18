def yaksu(i):
    tem = []
    
    # 약수 구하기 => 나머지가 0이 되는게 약수
    for j in range(1 ,i+1):

        if i % j == 0:
            #j는 약수가 된다.
            tem.append(j)
    return tem
    

# 최소공배수 = 두수의 곱 / 두수의 최대공약수
def solution(arr):
    answer = 0
    stack = []
    
    for i in arr:
        # list를 set으로 바꾸기
        # 공집합을 구하기 위해서
        stack.append(set(yaksu(i)))
        
        
    length=len(arr)
    
    for i in range(length):
        #i+1이기 때문에 마지막 무시
        if i == length-1:
            continue
        else:
            n = stack[i] & stack[i+1] #공약수
            max_n = max(n) #최대 공약수
            mul = arr[i] * arr[i+1]
            ans = mul / max_n
            if ans != arr[i+1]:
                arr[i+1] = ans
                stack[i+1] = set(yaksu(int(ans)))
            
    answer = ans
    
    return answer
