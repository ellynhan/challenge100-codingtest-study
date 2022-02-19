import sys

data = []

num_student = int(sys.stdin.readline())
for i in range(num_student) :
    student = list(sys.stdin.readline().split())
    student.reverse()
    student[0] = int(student[0])
    student[1] = int(student[1])
    student[2] = int(student[2])
    data.append(student)

data.sort(reverse = True)
print(f"{data[0][3]} {data[-1][3]}")
