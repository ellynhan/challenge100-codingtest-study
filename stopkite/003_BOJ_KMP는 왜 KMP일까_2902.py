arr = list(input().split("-"))
kmp = ""
for elem in arr:
    kmp += elem[0]

print(kmp)