#
#   1965
#   자료구조 실버5
# #
import sys
hash_dict = dict()
input = sys.stdin.readline

n = int(input())
for i in range(n):
    name,do = map(str,input().split())
    if do =='enter':
        hash_dict[name] = 1
    elif do=='leave':
        del hash_dict[name]
    #print(arr_hash)
hash_dict = sorted(hash_dict.keys(),reverse=True)
for i in hash_dict:
    print(i)
