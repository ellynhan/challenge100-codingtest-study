
import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

N, score, P = map(int, input().split())
# 랭킹 리스트에 올라 갈 수 있는 점수의 개수 P가 
# 그리고 리스트에 있는 점수 N개가 비오름차순
# 태수의 새로운 점수

if N == 0:
    print(1)
else:
    arr = [0 for _ in range(N)]

    # 현재 랭킹 리스트에 있는 점수가 비오름차순
    arr = list(map(int, input().split()))
    arr.sort(reverse=True)

    if len(arr) == P: #일단 리스트는 만석임
        if arr[-1] >= score:
            print(-1)
        else: 
            arr.pop()
            arr.append(score)
            arr.sort(reverse=True)
            rank = 1
            for i in range(len(arr)):        
                if arr[i] <= score:
                    break
                rank += 1   
            print(rank)     

    else:
        rank = 1
        for i in range(len(arr)):        
            if arr[i] <= score:
                break
            rank += 1   
        print(rank)       
     
