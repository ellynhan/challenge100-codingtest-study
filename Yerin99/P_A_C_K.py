boxes = []
w = 0
h = 0

for i in range(3):
    box = sorted(map(int, input().split()), reverse=True)
    boxes.append(box)

boxes.sort(reverse=True)

if boxes[0][0] >= boxes[1][0] + boxes[2][0]:
    w = boxes[0][0]
    h = boxes[0][1] + max(boxes[1][1], boxes[2][1])
else:
    w = boxes[1][0] + boxes[2][0]
    h = boxes[0][1] + max(boxes[1][1], boxes[2][1])

print(pow(w, 2)+pow(h, 2))
