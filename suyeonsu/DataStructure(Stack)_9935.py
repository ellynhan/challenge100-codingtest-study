s = input()
bomb = input()

st = []
for x in s:
    st.append(x)
    if st[-1] == bomb[-1] and len(st) >= len(bomb):
        if all(st[i]==bomb[i] for i in range(-1, -len(bomb)-1, -1)):
            for _ in range(len(bomb)):
                st.pop()
print(''.join(st) if st else 'FRULA')
