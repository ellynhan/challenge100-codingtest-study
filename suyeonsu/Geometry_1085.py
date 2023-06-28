x, y, w, h = map(int, input().split())
print(min([x, y, abs(x-w), abs(y-h)]))
