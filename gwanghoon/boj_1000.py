import sys
if __name__ == "__main__":
    inputs = sys.stdin.readline()[:-1]
    ls = inputs.split()
    print(int(ls[0])-int(ls[1]))
