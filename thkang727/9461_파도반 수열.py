#
#   9461
#   수학 실버3
# #


t = int(input())
p = [1,1,1,2,2,3]

for _ in range(t):
    pn = int(input())
    for i in range(len(p),pn):
        p.append(p[i-2]+p[i-3])
    print(p[pn-1])
