import sys

a = int(sys.stdin.readline())
b = sys.stdin.readline().strip()

print(a*int(b[2]))
print(a*int(b[1]))
print(a*int(b[0]))
print(a*int(b))
