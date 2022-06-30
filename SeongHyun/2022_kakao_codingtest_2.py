def solution(n, k):
    def isPrime(num):
        for i in range(2,round((num)**(1/2))+1):
            if num%i == 0:
                return False
        return True
    
    answer = 0
    result_num = ""
    
    while n>0:
        n, mod = divmod(n, k)
        result_num = str(int(mod)) + result_num
    
    num_list = result_num.split("0")

    for num in num_list:
        if num == '1' or num=='':
            continue
        if isPrime(int(num)):
            answer+=1
            
    return answer
