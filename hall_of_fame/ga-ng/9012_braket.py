import sys

input = sys.stdin.readline

n = int(input())

for _ in range(n):
    lst = list(input().rstrip())
    score = 0
    
    while lst:
        temp = lst.pop()
        
        if temp == "(":
            score += 1
        else:
            score -= 1
        
        if score > 0:
            break
            
    
    if score == 0:
        print("YES")
    else:
        print("NO")