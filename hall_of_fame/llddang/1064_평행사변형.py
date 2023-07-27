import math

ax, ay, bx, by, cx, cy = input().split(" ")
ax = int(ax)
ay = int(ay)
bx = int(bx)
by = int(by)
cx = int(cx)
cy = int(cy)

if (bx - ax) * (cy - by) == (by - ay) * (cx - bx):
	print(-1.0)
	exit()

a = math.sqrt((ax - bx) ** 2 + (ay - by) ** 2)
b = math.sqrt((bx - cx) ** 2 + (by - cy) ** 2)
c = math.sqrt((cx - ax) ** 2 + (cy - ay) ** 2)

ma = max(a, b, c)
mi = min(a, b, c)
print(2 * (ma - mi))
