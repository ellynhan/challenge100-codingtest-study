precision = 4

import math

inputFile = open('station.inp', 'r')
outputFile = open('station.out', 'w')
A = list(map(lambda x: int(x), inputFile.readline().split()))
B = list(map(lambda x: int(x), inputFile.readline().split()))
C = list(map(lambda x: int(x), inputFile.readline().split()))
D = list(map(lambda x: int(x), inputFile.readline().split()))

middle = [0, 0, 0]

minPoint = D.copy()

dist1 = 0
dist2 = 0
prevDist1 = 0
prevDist2 = 1

flag1 = True
flag2 = True

while True:
  newPoint1 = A.copy()
  newPoint2 = B.copy()
  newPoint3 = C.copy()
  newPoint4 = D.copy()
  # find minimize point A,B line
  while True:
    dist1 = 0
    dist2 = 0
    for i in range(3):
      dist1 += (newPoint1[i] - minPoint[i]) ** 2
      dist2 += (newPoint2[i] - minPoint[i]) ** 2
      middle[i] = (newPoint1[i] + newPoint2[i]) / 2
    dist1 = round(math.sqrt(dist1), precision)
    dist2 = round(math.sqrt(dist2), precision)
    if dist1 == dist2:
      minPoint = middle.copy()
      break
    elif dist1 < dist2:
      newPoint2 = middle.copy()
    else:
      newPoint1 = middle.copy()

  # find minimize point C,D line
  while True:
    dist1 = 0
    dist2 = 0
    for i in range(3):
      dist1 += (newPoint3[i] - minPoint[i]) ** 2
      dist2 += (newPoint4[i] - minPoint[i]) ** 2
      middle[i] = (newPoint3[i] + newPoint4[i]) / 2
    dist1 = round(math.sqrt(dist1), precision)
    dist2 = round(math.sqrt(dist2), precision)
    if dist1 == dist2:
      minPoint = middle.copy()
      break
    elif dist1 < dist2:
      newPoint4 = middle.copy()
    else:
      newPoint3 = middle.copy()

  if prevDist1 == dist1 and prevDist2 == dist2:
    break
  prevDist1 = dist1
  prevDist2 = dist2


outputFile.write(str(math.ceil(dist1)))

inputFile.close()
outputFile.close()