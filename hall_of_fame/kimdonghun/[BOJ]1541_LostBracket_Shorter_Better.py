import sys

express = sys.stdin.readline()
#print(express)

tot = 0
accumulate_num = ""
minus_flag = False

for e in express:
    if e == "+" or e == "\n" or e == "-":
        #print("==" + str(tot))
        if minus_flag:
            tot -= int(accumulate_num)
            accumulate_num = ""
        else:
            tot += int(accumulate_num)
            accumulate_num = ""
        if e == "-":
            minus_flag = True
    else:
        accumulate_num += e
        #print(accumulate_num)

print(tot)