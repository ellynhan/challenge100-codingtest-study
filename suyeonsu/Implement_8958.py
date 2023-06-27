for _ in range(int(input())):
    answer = 0
    for o in list(input().split('X')):
        answer += len(o)*(len(o)+1)//2
    print(answer)
