N = int(input())
M = int(input())
if M > 0 :
    brokens = list(input().split())
else:
    brokens = []
    
result = abs(100-N)

def check(num):
    for n in str(num):
        if n in brokens:
            return False
    return True

gap = 0
while gap<result:
    minus_num = max(N-gap,0)
    pluse_num = N+gap
    if check(minus_num):
        result = min(result,gap + len(str(minus_num)))
        break
    elif check(pluse_num):
        result = min(result,gap + len(str(pluse_num)))
        break
    else:
        gap+=1

print(result)
