import sys

N = int(sys.stdin.readline())

s = []
stack_num = 0
stack_seq = ""

isValid = True
for i in range(N):
    cur_num = int(sys.stdin.readline())

    while(cur_num > stack_num):
        s.append(stack_num)
        stack_num += 1
        stack_seq += "+"
        #print("+")

    #print("==" , s[-1])
    if(cur_num <= stack_num):
        if(cur_num < s[-1] + 1):
            isValid = False
        s.pop()
        stack_seq += "-"

if isValid:
    print(*stack_seq, sep="\n")
else:
    print("NO")
