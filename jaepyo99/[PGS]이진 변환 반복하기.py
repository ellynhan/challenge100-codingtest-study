def binary(size):
    sen=""
    while(size>0):
        sen+=str(size%2)
        size=size//2
    return sen[::-1]
def make_only_one(sen):
    global cnt
    cnt+=1
    original_size=len(list(sen))
    new_sen=""
    for s in sen:
        if(s!='0'):
            new_sen+=s
    new_size=len(new_sen)
    if(new_sen=="1"):
        return (original_size-new_size)
    return (original_size-new_size)+make_only_one(binary(new_size))
def solution(s):
    global cnt
    cnt=0
    remove_size=make_only_one(s)
    return [cnt,remove_size]
