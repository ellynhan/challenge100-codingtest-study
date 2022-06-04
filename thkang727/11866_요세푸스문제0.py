#
#   구현 실버4
#  요세푸스 문제 0
#


a, b = map(int , input().split())
arr_n = [i for i in range(1, a+1)]
cnt, index_n= 0, 0
print('<', end="")

while(True):
    if cnt == a:
        break
    index_n += b
    if index_n > len(arr_n):
        index_n = index_n%len(arr_n)
        if index_n ==0:
            index_n+=len(arr_n)
    index_n-=1
    print(str(arr_n.pop(index_n)), end="")
    if cnt !=a-1:
        print(", ", end="")
    cnt+=1       
print('>', end="")
