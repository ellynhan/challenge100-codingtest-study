import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

S = input()



zero_section = 0
one_section = 0

if int(S[0]) == 0:
    zero_section += 1
else:
    one_section += 1    

for i in range(1,len(S)):
    
    if int(S[i-1]) != int(S[i]):
        if int(S[i]) == 1:
            one_section +=1
        else:
            zero_section +=1 

        

print(min(one_section,zero_section))