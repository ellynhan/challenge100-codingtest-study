n = list(map(int,input()))
s = len(n)//2

sum1 = sum(n[0:s])
sum2 = sum(n[s:])

if sum1 == sum2:
  print('LUCKY')
else:
  print('READY')
