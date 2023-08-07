s = input()
answer = 0
for x in ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']:
    answer += s.count(x)
    s = s.replace(x, ' ')
print(answer+len(s.replace(' ', '')))
