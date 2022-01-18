alpha = ['c=','c-','dz=','d-','lj','nj','s=','z=']
string = input()
count = 0
for i in alpha:
   if i in string:
       string = string.replace(i," ")
print(len(string))
