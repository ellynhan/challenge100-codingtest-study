import sys

my_lstr = sys.stdin.readline()
tot_time = 0

for i in range(len(my_lstr) - 1) :
    cur_num = ord(my_lstr[i]) - 65
    time_num = 2
    
    time_num += (cur_num // 3) + 1
    
    if my_lstr[i] == 'S' or my_lstr[i] == 'V' or my_lstr[i] == 'Y' or my_lstr[i] == 'Z' :
        time_num -= 1

    #print(time_num)
    tot_time += time_num

print(tot_time)
