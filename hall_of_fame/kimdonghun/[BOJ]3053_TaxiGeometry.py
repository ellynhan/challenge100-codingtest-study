import sys
import math

R = float(sys.stdin.readline())

euclid_geometry_area = R ** 2 * math.pi
print("{:6f}".format(euclid_geometry_area))
#print("{:.3f}".format(3.4599))
#print(round(euclid_geometry_area, 6))
taxi_geometry_area = R * R / 2 * 4
print("{:6f}".format(taxi_geometry_area))
#print(round(taxi_geometry_area, 6))