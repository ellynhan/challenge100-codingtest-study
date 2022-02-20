import sys

def change(operand1, operand2):
    temperand = operand1[:-2] + "00"
    o1 = int(temperand)
    o2 = int(operand2)
    remainder =  o1 % o2
    adds = o2 - remainder
    if remainder == 0:
        return "00"
    if adds < 10:
        return "0" + str(adds)
    else:
        return str(adds)
if __name__ == "__main__":
    operand1 = sys.stdin.readline()[:-1]
    operand2 = sys.stdin.readline()[:-1]
    print(change(operand1,operand2))

    "브2 6분20초"
