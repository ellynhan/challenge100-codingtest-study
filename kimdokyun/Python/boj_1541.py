read = input()
if read.find('-') == -1:
    print(sum(map(int,read.split('+'))))
else:
    frontSum = sum(map(int,read[:read.find('-')].replace('-','+').split('+')))
    backSum = sum(map(int,read[read.find('-')+1:].replace('-','+').split('+')))
    print(frontSum-backSum)
