import sys

def translator(line, diction):
    encoder = line.split()
    decoder = []
    for i in encoder:
        decoder.append(dictionary[i])
    return " ".join(decoder)

if __name__ == "__main__":
    diclen = int(sys.stdin.readline()[:-1])
    dictionary = dict()
    for i in range(diclen):
        inputLine = sys.stdin.readline()[:-1].split(" = ")
        dictionary[inputLine[0]] = inputLine[1]
    translen = int(sys.stdin.readline()[:-1])
    trans = []
    for i in range(translen):
        linelen = int(sys.stdin.readline()[:-1])
        line = sys.stdin.readline()
        trans.append(line)
    for i in trans:
        print(translator(i, dictionary))

# 5분
# 역시 파이썬은 문자열처리 깡패