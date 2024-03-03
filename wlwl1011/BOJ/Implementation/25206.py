import sys, os, io, atexit
input = lambda : sys.stdin.readline().rstrip('\r\n')
stdout = io.BytesIO()
sys.stdout.write = lambda s : stdout.write(s.encode("ascii"))
atexit.register(lambda : os.write(1, stdout.getvalue()))

ans = []
score_sum = 0
for _ in range(20):
    name, score, rank = input().split()
    if rank == 'A+':
        r = 4.5
    elif rank == 'A0':
        r = 4.0
    elif rank == 'B+':
        r = 3.5
    elif rank == 'B0':
        r = 3.0
    elif rank == 'C+':
        r = 2.5
    elif rank == 'C0':
        r = 2.0
    elif rank == 'D+':
        r = 1.5
    elif rank == 'D0':
        r = 1.0
    elif rank == 'F': 
        r = 0.0
    else: 
        continue                           
    score_sum += float(score)    
    ans.append(float(score)*r)
print(round(sum(ans)/score_sum,6))    
