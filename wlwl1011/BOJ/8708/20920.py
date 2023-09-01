import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

N, M = map(int, input().split())
arr = {}
for _ in range(N):
    word = input()
    #길이가 M이상인 단어
    if len(word) >= M:
        if word in arr:
            arr[word] += 1
        else:
            arr[word] = 1
# print('ex')            
# for key, value in arr.items():
#     print(key,value)            

arr = dict(sorted(arr.items()))#알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치한다
# print(3)    
# for key, value in arr.items():
#     print(key,value)      
arr = dict(sorted(arr.items(),key = lambda x: len(x[0]), reverse=True))
# print(2)    
# for key, value in arr.items():
#     print(key,value)  

arr = dict(sorted(arr.items(), key = lambda x: x[1], reverse=True))   
# print(1)    
# for key, value in arr.items():
#     print(key,value)  

for key, value in arr.items():
    print(key)
