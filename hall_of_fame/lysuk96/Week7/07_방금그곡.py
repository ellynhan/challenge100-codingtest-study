#https://programmers.co.kr/learn/courses/30/lessons/17683
#어려운 문제는 아닌데, 문제가 길어지니까 난독증이 옴..
#몇몇 string 모듈 기억할것 (replace, find 등)
from collections import defaultdict
def solution(m, musicinfos):
    arr = []
    def change(s):
        s = s.replace("C#", '0').replace("D#", '1').replace("F#", '2')\
            .replace("G#", '3').replace("A#", '4')
        return s
        
    m = change(m)
    # print('m', m)
    answer = ''
    for info in musicinfos:
        info = info.split(',')
        h = (int(info[1].split(':')[0]) - int(info[0].split(':')[0])) * 60
        minute = int(info[1].split(':')[1]) - int(info[0].split(':')[1])
        time = h + minute + 1
        arr.append([time, info[2], change(info[3])])
    arr.sort(key = lambda x: x[0], reverse = True)
    # print(arr)
    
    for time ,name, music in arr: # 이부분 없이 위에 있는 포문에 넣으면 시간복잡도 줄일 수 있음
        tmp = ''
        tmp += music * (time // len(music))
        tmp += music[:(time %len(music))]
        # print(tmp)
        if tmp.find(m) != -1:
            # print(tmp)
            return name
    
    return "(None)"

# 시간복잡도 줄인 풀이. 엥? 의외로 내 코드가 더 빠름
# def shap_to_lower(s):
#     s = s.replace('C#','c').replace('D#','d').replace('F#','f').replace('G#','g').replace('A#','a')
#     return s

# def solution(m,musicinfos):
#     answer=[0,'(None)']   # time_len, title
#     m = shap_to_lower(m)
#     for info in musicinfos:
#         split_info = info.split(',')
#         time_length = (int(split_info[1][:2])-int(split_info[0][:2]))*60+int(split_info[1][-2:])-int(split_info[0][-2:])
#         title = split_info[2]
#         part_notes = shap_to_lower(split_info[-1])
#         full_notes = part_notes*(time_length//len(part_notes))+part_notes[:time_length%len(part_notes)]
#         if m in full_notes and time_length>answer[0]:
#             answer=[time_length,title]
#     return answer[-1]