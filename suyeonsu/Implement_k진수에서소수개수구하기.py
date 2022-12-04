def solution(n, k):
    x = ''
    while n:
        x = str(n%k) + x
        n //= k
    x = [int(num) for num in x.split('0') if num]
    
    answer = 0
    for num in x:
        if num in [1, 2]: 
            if num == 2: answer += 1
            continue
        for i in range(2, int(num**(1/2))+1):
            if num % i == 0: break
        else: answer += 1
    return answer
  
"""
소수 판별 꿀팁(상황에 따라 효율적인 방법을 고르자)
  특정 범위 내의 모든 소수를 찾는 경우 → 에라토스테네스의 체
  특정 숫자 N에 대한 소수 판별 → 2~제곱근까지 약수 탐색

바보같이 계속 루트구할 때 num**1/2하고 있었다. → 연산자 우선순위에 의해 num**1가 먼저 수행됨
"""
