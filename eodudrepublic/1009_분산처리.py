import sys

test_case_num = int(sys.stdin.readline())

for i in range(test_case_num) :
    a, b = map(int, sys.stdin.readline().split())
    c = a % 10

    if c == 0 :
        print(10)
        continue
    
    j = 2
    while True :
        if (a**j) % 10 == c :
            j -= 1 
            break
        else :
            j += 1
    
    if b % j == 0 :
        b = j
    else :
        b = b % j

    c = (a**b) % 10
    print(c)

    # print(a**b)
    # print(f"{a} {b} {j}")
