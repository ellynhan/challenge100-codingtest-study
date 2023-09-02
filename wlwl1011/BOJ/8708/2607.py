import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s: stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

N = int(input())
word = input()

check = 0
for _ in range(N-1):
    copy_word = word[:]
    new_word = input()
    #print('start!')
    max_cout = max(len(copy_word), len(new_word))
    temp = 0
    while len(copy_word) >= 1 and len(new_word) >= 1:
        
        if temp > max_cout:
            break
        #print(copy_word, new_word)
        index = 0
        flag = False
        while True:
            if index >= len(copy_word):
                flag = True
                break 
            if copy_word[index] in new_word:
                break
            index += 1
        if flag:
            break    
        w = copy_word[index]
        new_word = new_word.replace(w,'',1) #겹치는거 일단 눈에 보이는거 냅다 없애셈
        copy_word = copy_word.replace(w,'',1)
       
                
        temp += 1    
    #print('result:',copy_word, new_word)    
    if len(copy_word) == 0 and len(new_word) == 0 : #둘의 구성이 같다
        check +=1    
    elif (len(copy_word) == 0 and len(new_word) == 1) or (len(copy_word) == 1 and len(new_word) == 0): #한개를 더하거나 빼거나     
        check +=1    
    elif len(copy_word) == 1 and len(new_word) == 1 : #한 글자 체인지
        check +=1
          
print(check)