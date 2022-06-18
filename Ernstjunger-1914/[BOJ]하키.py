import sys

def main():
  sysinput=sys.stdin.readline

  w, h, x, y, p=map(int, sysinput().split())
  cnt=0

  for _ in range(p):
    _x, _y=map(int, sysinput().split())

    if (x<=_x<=x+w) and (y<=_y<=y+h):
      cnt+=1
      continue

    r=h/2
    d1=((_x-x)**2+(_y-(y+r))**2)**0.5
    d2=((_x-(x+w))**2+(_y-(y+r))**2)**0.5

    if d1<=r or d2<=r:
      cnt+=1

  print(cnt)
  
if __name__=='__main__':
  main()