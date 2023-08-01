#https://programmers.co.kr/learn/courses/30/lessons/42839
# permutations 찾기! python set에는 사칙연산 가능!

from itertools import permutations
def solution(numbers):
    def is_prime(num):
        for i in range(2, int(num**0.5+1)): #루트 num까지만 확인하면 된다고 함..
            if num % i == 0:
                return False
        return True
    
    perms = set([])
    for i in range(1, len(numbers)+1):
        tmp = set([''.join(p) for p in permutations(numbers, i)])
        tmp = set(map(int, tmp))
        perms |= tmp
    
    perms -= {0,1}
    print(perms) 
    answer = 0
    for num in perms:
        if is_prime(num):
            answer+=1
        
    return answer