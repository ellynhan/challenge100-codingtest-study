n = int(input())
data = list(input().split())

a=0
b=0

for i in range(len(data)):
  if data[i] == 'L' and (a-1)>=0:
    a-=1
  elif data[i] == 'R' and (a+1)<n:
    a+=1
  elif data[i] == 'U' and (b-1)>=0:
    b-=1
  elif data[i] == 'D' and (b+1)<n:
    b+=1

print(b+1, a+1)

