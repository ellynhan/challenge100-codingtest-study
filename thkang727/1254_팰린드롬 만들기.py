#
#   1254
#   문자열 실버1
# #




s = input()

for _ in range(len(s)):
    tmp = s[_:]
    if s[_:]==tmp[::-1]:
        print(len(s)+_)
        break
            
