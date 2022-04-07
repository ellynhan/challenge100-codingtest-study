#
#   1010
#   dp 실버5
# #





t = int(input())

for i in range(t):
    n,m = map(int,input().split())
    nfact, mfact, mminnfact=1,1,1
    for j in range(2,m+1):
        mfact*=j
    for j in range(2,n+1):
        nfact*=j
    for j in range(2,m-n+1):
        mminnfact*=j
    ans = mfact//(nfact*mminnfact)
    print(ans)
