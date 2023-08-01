import sys

def main():
  while True:
    l, w, a=map(int, input().split())
    
    if l==w==a==0:
      break
    
    if l==0:
      l=a//w
    elif w==0:
      w=a//l
    else:
      a=l*w

    print(l, w, a)
  
if __name__=='__main__':
  main()