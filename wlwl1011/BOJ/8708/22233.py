import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

N, M = map(int, input().split()) #메모장에 적은 키워드수, #블로그에 쓴 글의 개수
keyword = dict()

for i in range(N):#메모장에 적은 키워드
    word = input()
    keyword[word] = 1

for i in range(M): #가회가 쓴 글과 관련된 키워드
    k = list(input().split(','))
    #print(k)
    for j in range(len(k)):
        if k[j] in keyword:
            keyword.pop(k[j])
  
    print(len(keyword))    



