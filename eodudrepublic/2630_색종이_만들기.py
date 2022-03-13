import sys

paper = [[]]
N = int(sys.stdin.readline())
for i in range(N):
    paper[0].append(list(map(int,sys.stdin.readline().split())))
# print(paper)

def a_color(paper) :
    color = paper[0][0]
    for i in paper :
        for j in i :
            if j != color :
                return -1
    return color
# print(a_color(paper[0]))

def done(t_list) :
    for i in t_list :
        if i == 0 or i == 1 :
            pass
        else :
            return True
    return False       
# test_list = [0, 0, 1, 1]
# print(done(test_list))

while done(paper) :
    for i in paper :
        if i == 0 or i == 1 :
            pass
        else :
            p = a_color(i)
            if p != -1 :
                paper.append(p)
                paper.remove(i)
            else :
                l = int(len(i)/2)
                for j in range(0, l*2, l) :
                    for k in range(0, l*2, l) :
                        paper.append([row[k:k+l] for row in i[j:j+l]])
                paper.remove(i)
    # print(f"----{N}----")
    # print(paper)
    N = N / 2

# print(paper)
print(paper.count(0))
print(paper.count(1))
