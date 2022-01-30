import sys

while(1):
    inp = sys.stdin.readline().rstrip()
    if inp=='0':
        break

    else:
        su = int(inp)
        wordORI = []
        wordUP = []
        for _ in range(su):
            word = input()
            wordORI.append(word)
            wordUP.append(word.upper())

        wordUP.sort()

        for i in wordORI:
            if  i.upper() == wordUP[0]:
                print(i)
