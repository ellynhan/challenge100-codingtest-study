def t2hnm(t):
    return t//60, t%60

h, m = map(int, input().split())
ht, mt = t2hnm(int(input()))

h += ht
m += mt

if m >= 60:
    m -= 60
    h += 1
    
if h >= 24:
    h -= 24
    
print(h, m)
