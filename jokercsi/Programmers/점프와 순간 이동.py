def solution(n):
    ans = 0
    
    while True:
        n, r= divmod(n, 2)

        if (r == 1):
            ans += 1
        if (n == 0):
            break
        
    return ans
