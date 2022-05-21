import sys

def cut_to_4(list_2D) :
    # print('---cut---')
    # print(list_2D)
    l = int(len(list_2D)/2)
    cut_list = []
    for j in range(0, l*2, l) :
        for k in range(0, l*2, l) :
            cut_list.append([row[k:k+l] for row in list_2D[j:j+l]])
    return cut_list

def a_color(list_2D) :
    # print('---color---')
    # print(list_2D)
    color = list_2D[0][0]
    for list in list_2D :
        for i in list :
            if i != color :
                return -1
    return color

def compress(video) :
    color = a_color(video)
    if color == '0' or color == '1' :
        return color
    else :
        vid = cut_to_4(video)
        # print('---compress---')
        # print(vid)
        return [compress(vid[0]), compress(vid[1]), compress(vid[2]), compress(vid[3])]

video = []
N = int(sys.stdin.readline())
for i in range(N):
    video.append(list(sys.stdin.readline().strip()))

compressed = "".join([str(_) for _ in [compress(video)]])
complete_video = ""
for i in compressed :
    if i == '0' or i == '1' :
        complete_video += i
    elif i == '[' :
        complete_video += '('
    elif i == ']' :
        complete_video += ')'
    else :
        pass
print(complete_video)
