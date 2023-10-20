import sys
import copy
input = lambda : sys.stdin.readline().rstrip('\r\n')

yeondu = input()
yeondu_dict = {'L':0, 'O':0, 'V':0, 'E':0}


for y in yeondu:
    if y in yeondu_dict:
        yeondu_dict[y] += 1

N = int(input())
arr = []
for _ in range(N):
    name = input()
    name_dict = copy.deepcopy(yeondu_dict)
    for n in name:
        if n in name_dict:
            name_dict[n] += 1
    #((L+O) × (L+V) × (L+E) × (O+V) × (O+E) × (V+E)) mod 100
    p = ((name_dict['L']+name_dict['O']) * (name_dict['L']+name_dict['V']) * (name_dict['L']+name_dict['E'])* (name_dict['O']+name_dict['V']) * (name_dict['O']+name_dict['E'])* (name_dict['V']+name_dict['E'])) % 100                   
    arr.append([p, name])
arr.sort(key = lambda x :(-x[0],x[1]))    
print(arr[0][1])