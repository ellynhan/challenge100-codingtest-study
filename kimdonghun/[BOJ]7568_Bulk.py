import sys

N = int(sys.stdin.readline())
tot_list = []

for n in range(N):
    cur_list = list(map(int,sys.stdin.readline().split()))
    tot_list.append(cur_list)

grade_l = [0] * len(tot_list)

#print(len(tot_list))

for i in range(len(tot_list)):
    cur_grade = 1

    for j in range(len(tot_list)):
        weight_prior = False
        height_prior = False

        if i != j:
            if tot_list[i][0] < tot_list[j][0]:
                weight_prior = True
            if tot_list[i][1] < tot_list[j][1]:
                height_prior = True

            if weight_prior and height_prior:
                cur_grade += 1

    grade_l[i] = cur_grade

for i in range(len(tot_list)):
    print(grade_l[i], end=" ")
#print(tot_list)
