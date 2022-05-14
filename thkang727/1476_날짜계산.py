#
#   1476
#   문자열
# #


e,s,m = map(int, input().split())
#print(e)
#print(s)
#print(m)
ans = 1
i,k,j = 1,1,1
while True:
    if i == 16:
        #print('i ')
        i = 1
    if k == 29:
        #print('k ')
        k = 1
    if j == 20:
        #print(' j')
        j = 1
    if i == e and k == s and j == m:
        print(ans)
        break

    i+=1
    j+=1
    k+=1
    ans +=1
    #print (i, ' ', k, ' ', j, ' ')
