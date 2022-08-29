def solution(dirs):
    path = set()
    d = {'U':(0, 1), 'D':(0, -1), 'R':(1, 0), 'L':(-1, 0)}
    
    x, y = 0, 0
    for s in dirs:
        xx, yy = x + d[s][0], y + d[s][1]
        if -5 <= xx <= 5 and -5 <= yy <= 5:
            path.add((x, y, xx, yy))
            path.add((xx, yy, x, y))
            x, y = xx, yy
            
    return len(path) // 2
