#
#   11656   접미사 배열
#   문자열 실버4
# #


s = input()

suf = []
for i in range(len(s)):
    suf.append(s[i:])

suf.sort()
for i in suf:
    print(i)
