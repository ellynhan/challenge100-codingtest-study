n,m,k = map(int, input().split())
data  = list(map(int, input().split()))

data.sort()
Biggest = data[n-1]
LBiggest = data[n-2]

result = 0

while(m>0):
  for i in range (k):
    result += Biggest
    m -= 1
  result += LBiggest
  m -= 1

print(result)
