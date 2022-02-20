data = []

for i in range(int(input())):
    number, age, gender = input().split()
    number = int(number)
    age = int(age)

    if age >= 61:
        age_priority = 0
    elif age <= 15:
        age_priority = 1
    else:
        age_priority = 2

    if age_priority == 0:
        if gender == "M":
            gender_priority = 0
        else:
            gender_priority = 1
    elif age_priority == 2:
        if gender == "F":
            gender_priority = 0
        else:
            gender_priority = 1
    else:
        gender_priority = 0

    data.append([number, age_priority, gender_priority])

data.sort(key=lambda x: (x[1], x[2]))

for entry in data:
    print(entry[0])
