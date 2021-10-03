import sys
def left(x):
    return x
def right(x,w):
    return w-x
def down(y):
    return y
def top(y,h):
    return h-y

def shortest(x,y,w,h):
    return min(left(x),right(x,w),down(y),top(y,h))

if __name__ == "__main__":
    x,y,w,h = sys.stdin.readline()[:-1].split()
    print(shortest(int(x),int(y),int(w),int(h)))

"""3분 12초"""
