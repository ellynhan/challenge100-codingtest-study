#
#   9655
#   dp
# 
# #
# 

croatia = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']

input_str = input()
ans=''
for _ in croatia:
    input_str=input_str.replace(_,'+')
    #print(ans)
print(len(input_str))
