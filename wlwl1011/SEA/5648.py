dx = [-1,1,0,0]
dy = [0,0,-1,1]

for tc in range(1, 1 + int(input())):
    n = int(input())
    atoms = []
    for i in range(n):
        x, y, d, k = map(int, input().split())
        x = (x+1000)*2
        y = (y+1000)*2
        atoms.append([x,y,d,k])

    total = 0
    while len(atoms) >= 2:
        loc = []
        hit = set()
        nex_atoms = []
        for i in range(len(atoms)):
            x, y, d, k = atoms[i]
            nx = x + dx[d]
            ny = y + dy[d]
            if 0 <= nx <= 4000 and 0 <= ny < 4000:
                if (nx,ny) in loc:
                    hit.add((nx,ny))
                else:
                    loc.append((nx,ny))
                nex_atoms.append((nx,ny,d,k))          
        atoms = []
        for i in range(len(nex_atoms)):
            x, y, d, k = nex_atoms
            if (x,y) in hit:
                total += k
            else:
                atoms.append((x,y,d,k)) 
    print(f'#{tc} {total}')                       