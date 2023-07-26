def solve(x, y, w, h):
    if x < w / 2 :
        can1 = x
    else :
        can1 = w - x
        
    if y < h / 2 :
        can2 = y
    else :
        can2 = h - y

    return min(can1, can2)

x, y, w, h = map(int, input().split())
print(solve(x,y,w,h))    

