import sys

def draw_star(n, l):
    ans = []
    
    if n == 3:
        return l
    else:
        for i in l:
            ans.append(i * 3)
        for i in l:
            ans.append(i + ' ' * len(l) + i)
        for i in l:
            ans.append(i * 3)

        #print(ans)

        return draw_star(n//3, ans)
    

N = int(sys.stdin.readline())
base = ['***', '* *', '***']
res = draw_star(N, base)

for i in res:
    print(i)