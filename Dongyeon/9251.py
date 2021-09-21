#백준 9251번 LCS

line1 = input()
line2 = input()

len1 = len(line1)
len2 = len(line2)

matrix = [[0 for _ in range(len2+1)] for _ in range(len1+1)]

for i in range(1, len1 + 1):
    for j in range(1, len2 + 1):
        if line1[i - 1] == line2[j - 1]:
            matrix[i][j] = matrix[i - 1][j - 1] + 1
        else:
            matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1])
print(matrix[-1][-1])
