import sys
class frequency:
    def __init__(self, inputSentence):
        self.inputSentence = inputSentence.lower().replace(" ","")
        self.freqSet = set(self.inputSentence)
        self.freqDict = {}
        for i in self.freqSet:
            if i.isalpha():
                self.freqDict[i] = 0
        for i in self.inputSentence:
            if i.isalpha():
                self.freqDict[i] += 1
    def getMax(self):
        result = []
        maxVal = max(self.freqDict.values())
        for i in self.freqDict.keys():
            if self.freqDict[i] == maxVal:
                result.append(i)
        result.sort()
        return "".join(result)
if __name__ == "__main__":
    inputSentence = sys.stdin.read()
    x = frequency(inputSentence).getMax()
    print(x)
