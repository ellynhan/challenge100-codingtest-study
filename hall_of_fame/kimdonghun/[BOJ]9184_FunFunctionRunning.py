import sys
w_list = [[[0 for col in range(101)] for row in range(101)] for depth in range(101)]

def w(a,b,c):
    if a <= 0 or b <= 0 or c <= 0:
        return 1
    elif w_list[a][b][c] != 0:
        return w_list[a][b][c]
    else:
        if a > 20 or b > 20 or c > 20 :
            return w(20,20,20)
        elif a < b and b < c:
            w_list[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
            return  w_list[a][b][c]
        else:
            w_list[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
            return  w_list[a][b][c]

#print(w_list)

while True:
    a,b,c = map(int, sys.stdin.readline().split())
    #print(a,b,c)
    if(a == -1 and b == -1 and c == -1):
        break

    print(f'w({a}, {b}, {c}) = {w(a,b,c)}')

