def solution(s):
    answer = 0
    numDict = {
        "zero": 0, "one": 1, "two": 2,
        "three": 3, "four": 4, "five": 5,
        "six": 6, "seven": 7, "eight": 8, "nine": 9}

    convertedString = ""

    characterBuffer = ""

    for i in s:
        if(i >= '0' and i <= '9'):
            # numeric
            convertedString += i
        else:
            # character
            
            characterBuffer += i
            if(len(characterBuffer)>2 and characterBuffer in numDict):
                convertedString += str(numDict[characterBuffer])
                characterBuffer = str()

    answer = int(convertedString)
    return answer
