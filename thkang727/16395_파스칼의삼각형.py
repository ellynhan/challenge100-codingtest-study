#
#   16395
#   dp 실버5
# #

n,k = map(int, input().split())
pascal_li = [[1], [1,1]]
for i in range(2,n):
    tmp=[1]
    for j in range(1,i):
        tmp.append(pascal_li[i-1][j-1]+pascal_li[i-1][j])
    tmp.append(1)
    pascal_li.append(tmp)
print(pascal_li[n-1][k-1])
