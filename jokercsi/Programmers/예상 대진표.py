# n = 참가자 수
# a = 주인공 번호
# b = 라이벌 번호

# 1 2 3 4 5 6 7 8   (height = 1)
#  1   2   3   4    (height = 2)
#    1       2      (height = 3)
#        1          (height = 4)

def oddeven(n):
    if n % 2 == 0:
        return n
    else:
        n = n + 1
        return n

def solution(n,a,b):
    answer = 0
    height = 1 # height of graph (round)
    
    while True:
        n /= 2
        
        a = oddeven(a) / 2
        b = oddeven(b) / 2
        
        print(a, b)
        # 1라운드에서부터 만날경우 
        if b - a == 0:
            break
            
        height += 1
              
        # 같은 층일 때
        if oddeven(a) == oddeven(b):
            break

        if n == 1:
            break
            
    # 짝수 홀수
    answer = height
        
    return answer
