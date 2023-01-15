def rotate(num, d):
    if d == 1:
        wheel[num] = wheel[num][7] + wheel[num][:7]
    if d == -1:
        wheel[num] = wheel[num][1:] + wheel[num][0]

def cw(num, d):
    if num == 3:
        return 
    
    if wheel[num][2] != wheel[num+1][6]:
        isRotate[num+1] = d * -1
        cw(num+1, d*(-1))

def ccw(num, d):
    if num == 0:
        return
    
    if wheel[num][6] != wheel[num-1][2]:
        isRotate[num-1] = d * -1
        ccw(num-1, d*(-1))
        
def check(num, d):
    isRotate[num] = d
    cw(num, d)
    ccw(num, d)
    
    for i in range(4):
        rotate(i, isRotate[i])

    
wheel = [input() for _ in range(4)]
k = int(input())
for _ in range(k):
    num, d = map(int, input().split())
    isRotate = [0]*4
    check(num-1, d)
    
total = 0
for i in range(4):
    if wheel[i][0] == '1':
        total += 2 ** i

print(total)
