s = 0
tot = 0
d = {'A+': 4.5, 'A0': 4.0, 'B+': 3.5, 'B0': 3.0, 'C+': 2.5, 'C0': 2.0, 'D+': 1.5, 'D0': 1.0, 'F': 0.0}
for _ in range(20):
    _, unit, grade = input().split()
    if grade != 'P':
        s += float(unit)*d[grade]
        tot += float(unit)
print(round(s/tot, 6))
