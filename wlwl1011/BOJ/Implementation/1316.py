import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

N = int(input())
ans = 0
for _ in range(N):
    flag = True
    word = input()
    start = word[0]
    dictionary = dict()
    dictionary[start] = 1
    for i in range(1, len(word)):
        if start != word[i]:
            if word[i] not in dictionary:
                dictionary[word[i]] = 1
                start = word[i] #갱신
            else:
                flag = False
                break  

    if flag:
        ans += 1    
print(ans)              

