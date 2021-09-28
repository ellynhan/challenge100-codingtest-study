def exec_code(func_name):
    for statement in codes[func_name]:
        if statement.isupper():
            exec_code(statement)
        else:
            execution.append(func_name+"-"+statement)


n, k1, k2 = map(int, input().split())

codes = {}

for _ in range(n):
    line = input().split()
    f = line[0]
    statements = line[1:-1]
    codes[f] = statements

execution = []

try:
    exec_code("M")
    try:
        print(execution[k1-1])
    except IndexError:
        print("NONE")
    try:
        print(execution[k2-1])
    except IndexError:
        print("NONE")
except RecursionError:
    print("DEADLOCK")

