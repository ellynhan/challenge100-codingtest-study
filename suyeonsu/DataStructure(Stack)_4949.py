while True:
    s = input()
    if s == '.': break
    st = []
    for x in s:
        if x == '(' or x == '[': st.append(x)
        elif x == ')':
            if st and st[-1] == '(': st.pop()
            else: break
        elif x == ']':
            if st and st[-1] == '[': st.pop()
            else: break
    else:
        print('no' if st else 'yes')
        continue
    print('no')
