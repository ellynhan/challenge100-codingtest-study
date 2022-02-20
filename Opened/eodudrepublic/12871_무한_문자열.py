import sys

s = sys.stdin.readline().strip()
t = sys.stdin.readline().strip()

len_s = len(s)
len_t = len(t)

s = s * len_t
t = t * len_s

if s == t :
    print(1)
else :
    print(0)
# ...위의 방법을 쓰니 5분만에 풀었는데, 아래의 코드로 풀 수 없는 반례가 있던걸까요... ㅠㅠ


# 이 코드를 2시간 걸려 쓴 배냇병신이 여기있습니다! WA!
# while True :
#     s = sys.stdin.readline().strip()
#     t = sys.stdin.readline().strip()

#     s1 = set(s)
#     s2 = set(t)
#     if len(s1) == 1 and len(s2) == 1 and s1 == s2 :
#         print(1)
#         break

#     len_s = len(s)
#     len_t = len(t)

#     if len_s > 50 or len_t > 50 :
#         print(0)
#         break

#     if len_s >= len_t :
#         len_long = len_s
#         len_short = len_t
#         str_long = s
#         str_short = t
#     else :
#         len_long = len_t
#         len_short = len_s
#         str_long = t
#         str_short = s
        
#     if len_t % len_s != 0 :
#         print(0)
#         break

#     temp = str_short
#     temp_len = len_short
#     while temp_len <= 50 :
#         if temp == str_long :
#             temp_len = 0
#             print(1)
#             break
#         temp += str_short
#         temp_len += len_short
#     if temp_len != 0 :
#         print(0)
#     break
