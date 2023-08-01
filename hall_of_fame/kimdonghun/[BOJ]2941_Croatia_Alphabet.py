import sys

word = sys.stdin.readline()

letters = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]
new_word = word.strip()

for i in letters :
    #print(i)
    new_word = new_word.replace(i, "p")

#print(new_word)
print(len(new_word))
