N,M = map(int,input().split())
nameDic = {}
numDic = {}
for i in range(1,N+1):
    name = input()
    nameDic[name] = i
    numDic[i] = name
for i in range(M):
    quiz = input()
    if quiz.isdigit():
        print(numDic[int(quiz)])
    else:
        print(nameDic[quiz])
    
