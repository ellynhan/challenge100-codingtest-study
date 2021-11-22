s = ""
f = open("/NESPA/sapiens.txt", "r")
lines = f.readlines()[1:]
for line in lines:
    s += line.strip()
f.close()

for _ in range(int(input())):
    operation, i, j = input().split()
    i, j = int(i) - 1, int(j) - 1

    if operation == "front":
        s = s[i:j+1] + s[:i] + s[j+1:]
    elif operation == "back":
        s = s[:i] + s[j+1:] + s[i:j+1]
    elif operation == "cut":
        s = s[:i] + s[j+1:]
    elif operation == "double":
        s = s[:i] + s[i:j+1]*2 + s[j+1:]
    elif operation == "flip":
        s = s[:i] + s[i:j+1][::-1] + s[j+1:]
    elif operation == "report":
        length = len(s)
        if i > length-1:
            print("NONE")
        elif j > length-1:
            print(s[i:])
        else:
            print(s[i:j+1])
