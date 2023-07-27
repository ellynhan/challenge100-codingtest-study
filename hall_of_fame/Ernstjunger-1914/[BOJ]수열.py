import sys

def main():
  input=sys.stdin.readline
  res=[]
  n, k=map(int, input().split())
  li=list(map(int, input().split()))

  res.append(sum(li[:k]))

  for i in range(n-k):
    res.append(res[i]-li[i]+li[k+i])

  print(max(res))
  
if __name__=='__main__':
  main()