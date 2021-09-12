import sys
class operators:
    def __init__(self, operands):
        self.operands = operands.split()
    def plus(self):
        return (int(self.operands[0]) + int(self.operands[1]) ) == int(self.operands[2])
    def minus(self):
        return (int(self.operands[0]) - int(self.operands[1]) ) == int(self.operands[2])
    def mul(self):
        return (int(self.operands[0]) * int(self.operands[1]) ) == int(self.operands[2])
    def div(self):
        return (int(self.operands[0]) / int(self.operands[1]) ) == int(self.operands[2])
    def _plus(self):
        return (int(self.operands[0]) == int(self.operands[1]) + int(self.operands[2]))
    def _minus(self):
        return (int(self.operands[0]) == int(self.operands[1]) - int(self.operands[2]))
    def _mul(self):
        return (int(self.operands[0]) == int(self.operands[1]) * int(self.operands[2]))
    def _div(self):
        return (int(self.operands[0]) == int(self.operands[1]) / int(self.operands[2]))

    def result(self):
        result_val = ""
        if self.plus(): return result_val + self.operands[0] + "+" + self.operands[1] + "=" + self.operands[2]
        if self.minus(): return result_val + self.operands[0] + "-" + self.operands[1] + "=" + self.operands[2]
        if self.mul(): return result_val + self.operands[0] + "*" + self.operands[1] + "=" + self.operands[2]
        if self.div(): return result_val + self.operands[0] + "/" + self.operands[1] + "=" + self.operands[2]

        if self._plus(): return result_val + self.operands[0] + "=" + self.operands[1] + "+" + self.operands[2]
        if self._minus(): return result_val + self.operands[0] + "=" + self.operands[1] + "-" + self.operands[2]
        if self._mul(): return result_val + self.operands[0] + "=" + self.operands[1] + "*" + self.operands[2]
        if self._div(): return result_val + self.operands[0] + "=" + self.operands[1] + "/" + self.operands[2]

if __name__ == "__main__":
#    operands = sys.stdin.readline()
    operands = input()
    print(operators(operands).result())
