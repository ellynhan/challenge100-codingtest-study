def solution(s):
    answer = ""
    firstCursor = 0
    for secondCursor in range(len(s)):
        if s[firstCursor:secondCursor + 1] == "zero":
            firstCursor = secondCursor + 1
            answer += '0'
        elif s[firstCursor:secondCursor + 1] == "one":
            firstCursor = secondCursor + 1
            answer += '1'
        elif s[firstCursor:secondCursor + 1] == "two":
            firstCursor = secondCursor + 1
            answer += '2'
        elif s[firstCursor:secondCursor + 1] == "three":
            firstCursor = secondCursor + 1
            answer += '3'
        elif s[firstCursor:secondCursor + 1] == "four":
            firstCursor = secondCursor + 1
            answer += '4'
        elif s[firstCursor:secondCursor + 1] == "five":
            firstCursor = secondCursor + 1
            answer += '5'
        elif s[firstCursor:secondCursor + 1] == "six":
            firstCursor = secondCursor + 1
            answer += '6'
        elif s[firstCursor:secondCursor + 1] == "seven":
            firstCursor = secondCursor + 1
            answer += '7'
        elif s[firstCursor:secondCursor + 1] == "eight":
            firstCursor = secondCursor + 1
            answer += '8'
        elif s[firstCursor:secondCursor + 1] == "nine":
            firstCursor = secondCursor + 1
            answer += '9'
        elif s[firstCursor].isnumeric():
            answer += s[firstCursor]
            firstCursor += 1
            
    return int(answer)