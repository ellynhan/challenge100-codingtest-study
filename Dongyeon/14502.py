from itertools import combinations

def init_rand(a, b):
    tmmp_map = []
    for i in range(a):
        tmmp_map.append(list(range(int(b))))
    return tmmp_map

def init_row(map, rows, a, b):
    for i in range(len(rows)):
        for j in range(len(rows[0])):
            map[i][j] = rows[i][j]
    return map

def count(map):
    count = 0
    for i in range(len(map)):
        for j in range(len(map[0])):
            if map[i][j] == '0': count += 1
    return count

def spread(map, a, b):
    tmp_map = init_rand(a,b)
    for i in range(a):
        for j in range(b):
            tmp_map[i][j] = map[i][j]

    for i in range(len(tmp_map)):
        for j in range(len(tmp_map[0])):
            if map[i][j] == '2':
                try:
                    if (i != int(a)-1) & (map[i+1][j] == '0') : tmp_map[i+1][j] = '2'
                except IndexError : pass
                try:
                    if (i != 0) & (map[i-1][j] == '0') : tmp_map[i-1][j] = '2'
                except IndexError : pass
                try:
                    if (j != int(b)-1) & (map[i][j+1] == '0') : tmp_map[i][j+1] = '2'
                except IndexError : pass
                try:
                    if (j != 0) & (map[i][j-1] == '0') : tmp_map[i][j-1] = '2'
                except IndexError : pass

    if map == tmp_map : return tmp_map, True
    else : return tmp_map, False

def print_map(map):
    for i in range(len(map)):
        print(' '.join(map[i]))

def check_0_position(map, a, b):
    list_zero = []
    for i in range(a):
        for j in range(b):
            if map[i][j] == '0': list_zero.append([i, j])
    return list_zero

def make_wall(map, a, b, tup):
    tmp_map = init_rand(a, b)
    for i in range(a):
        for j in range(b):
            tmp_map[i][j] = map[i][j]
    for cordinate in tup:
        tmp_map[cordinate[0]][cordinate[1]] = '1'
    return tmp_map


dim = input().split()
a = int(dim[0])
b = int(dim[1])
rows = []
for i in range(int(dim[0])):
    rows.append(input().split())

map = init_rand(a, b)
map = init_row(map, rows, a, b)


subset = list(combinations(check_0_position(map, a, b), 3))
count_list = []
for tup in subset:
    mapa = make_wall(map, a, b, tup)
    while True:
        mapa, t = spread(mapa, a, b)
        if t: break
    count_list.append(int(count(mapa)))
print(max(count_list))
