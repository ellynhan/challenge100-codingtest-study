def solution(n):
    if n == 0 or n == 3: return '4'
    if n == 1 or n == 2: return str(n)
    if n % 3 == 0:
        return solution(n//3 - 1) + solution(n%3)
    else:
        return solution(n//3) + solution(n%3)
