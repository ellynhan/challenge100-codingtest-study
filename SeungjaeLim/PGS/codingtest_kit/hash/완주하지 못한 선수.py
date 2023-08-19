def solution(participant, completion):
    pdict = {}
    for p in participant:
        if p in pdict:
            pdict[p] += 1
        else:
            pdict[p] = 1
    for c in completion:
        pdict[c] -= 1
    for k,v in pdict.items():
        if v != 0:
            return k
        