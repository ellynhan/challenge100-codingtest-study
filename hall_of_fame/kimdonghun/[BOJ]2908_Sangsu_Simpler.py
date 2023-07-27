import sys

str1, str2 = sys.stdin.readline().split()

'''
slist1 = list(str1)
slist1.reverse()
slist2 = list(str2)
slist2.reverse()

n1 = int(''.join(slist1))
n2 = int(''.join(slist2))
'''

n1 = int(str1[::-1])
n2 = int(str2[::-1])

#print(slist1, slist2)

if n1 > n2 :
    print (n1)
else :
    print (n2)