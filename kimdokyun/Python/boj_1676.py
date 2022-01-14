N = int(input())
cnt2 = 0
cnt5 = 0
for i in range(1,N+1):
    while i%2==0:
        cnt2+=1
        i/=2
    while i%5==0:
        cnt5+=1
        i/=5
print(min(cnt2,cnt5))
