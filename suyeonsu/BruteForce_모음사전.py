from itertools import product

def solution(word):
    d = sorted([''.join(w) for k in range(1, 6) for w in list(product(['A', 'E', 'I', 'O', 'U'], repeat=k))])
    return d.index(word)+1
