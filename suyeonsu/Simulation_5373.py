t = int(input())
for _ in range(t):
    n = int(input())
    up = [['w'] * 3 for _ in range(3)]
    down = [['y'] * 3 for _ in range(3)]
    front = [['r'] * 3 for _ in range(3)]
    back = [['o'] * 3 for _ in range(3)]
    left = [['g'] * 3 for _ in range(3)]
    right = [['b'] * 3 for _ in range(3)]
    for cmd in input().split():
        if cmd == 'L-':
            left = [lst for lst in list(map(list, zip(*left)))[::-1]]
            for i in range(3):
                front[i][0], down[i][0], back[2-i][2], up[i][0] = down[i][0], back[2-i][2], up[i][0], front[i][0]
        elif cmd == 'L+':
            left = [lst for lst in list(map(list, zip(*left[::-1])))]
            for i in range(3):
                front[i][0], up[i][0], back[2-i][2], down[i][0] = up[i][0], back[2-i][2], down[i][0], front[i][0]
        elif cmd == 'R-':
            right = [lst for lst in list(map(list, zip(*right)))[::-1]]
            for i in range(3):
                front[i][2], up[i][2], back[2-i][0], down[i][2] = up[i][2], back[2-i][0], down[i][2], front[i][2]
        elif cmd == 'R+':
            right = [lst for lst in list(map(list, zip(*right[::-1])))]
            for i in range(3):
                front[i][2], down[i][2], back[2-i][0], up[i][2] = down[i][2], back[2-i][0], up[i][2], front[i][2]
        elif cmd == 'U-':
            up = [lst for lst in list(map(list, zip(*up)))[::-1]]
            front[0], left[0], back[0], right[0] = left[0], back[0], right[0], front[0]
        elif cmd == 'U+':
            up = [lst for lst in list(map(list, zip(*up[::-1])))]
            front[0], right[0], back[0], left[0] = right[0], back[0], left[0], front[0]
        elif cmd == 'D-':
            down = [lst for lst in list(map(list, zip(*down)))[::-1]]
            front[2], right[2], back[2], left[2] = right[2], back[2], left[2], front[2]
        elif cmd == 'D+':
            down = [lst for lst in list(map(list, zip(*down[::-1])))]
            front[2], left[2], back[2], right[2] = left[2], back[2], right[2], front[2]
        elif cmd == 'F-':
            front = [lst for lst in list(map(list, zip(*front)))[::-1]]
            u = list(map(list, zip(*right)))[::-1]
            r = list(map(list, zip(*down)))[::-1]
            d = list(map(list, zip(*left)))[::-1]
            l = list(map(list, zip(*up)))[::-1]
            for i in range(3):
                up[2][i], right[i][0], down[0][i], left[i][2] = u[2][i], r[i][0], d[0][i], l[i][2]
        elif cmd == 'F+':
            front = [lst for lst in list(map(list, zip(*front[::-1])))]
            u = list(map(list, zip(*left[::-1])))
            l = list(map(list, zip(*down[::-1])))
            d = list(map(list, zip(*right[::-1])))
            r = list(map(list, zip(*up[::-1])))
            for i in range(3):
                up[2][i], left[i][2], down[0][i], right[i][0] = u[2][i], l[i][2], d[0][i], r[i][0]
        elif cmd == 'B-':
            back = [lst for lst in list(map(list, zip(*back)))[::-1]]
            u = list(map(list, zip(*left[::-1])))
            l = list(map(list, zip(*down[::-1])))
            d = list(map(list, zip(*right[::-1])))
            r = list(map(list, zip(*up[::-1])))
            for i in range(3):
                up[0][i], left[i][0], down[2][i], right[i][2] = u[0][i], l[i][0], d[2][i], r[i][2]
        else:
            back = [lst for lst in list(map(list, zip(*back[::-1])))]
            u = list(map(list, zip(*right)))[::-1]
            r = list(map(list, zip(*down)))[::-1]
            d = list(map(list, zip(*left)))[::-1]
            l = list(map(list, zip(*up)))[::-1]
            for i in range(3):
                up[0][i], right[i][2], down[2][i], left[i][0] = u[0][i], r[i][2], d[2][i], l[i][0]
    for u in up:
        print(''.join(u))
