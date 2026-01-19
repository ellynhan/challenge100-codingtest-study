import sys

#1. 배열 초기화
if 'list' in locals() or 'list' in globals():
    del list

my_list = []
print("데이터 입력 전 list : ", my_list)


# 2. 입력받기 
user_input = list(map(int, input("2개 이상의 정수 입력: ").split()))


#조건1) 만약 배열의 길이가 2 미만, 100,000 초과일 경우 종료
#조건2) 만약 배열의 원소가 -100000 미만, 100000 초과일 경우 종료
if len(user_input) < 2 or len(user_input) > 100000:
    print("입력받은 정수의 개수가 범위를 벗어납니다.")
    sys.exit()
else :
    for num in user_input:
        if num > 100000 or num < -100000:
            print(f"오류: 범위를 벗어난 숫자({num})가 감지되었습니다. 프로그램을 종료합니다.")
            sys.exit()


# 3. 입력받은 배열의 길이만큼만 슬라이싱하여 덮어쓰기
my_list[:len(user_input)] = user_input
print("데이터 정렬 전 list : ", my_list)


# 4. bubble sort로 정렬하기 (오름차순)
for k in range(len(my_list) - 1) :
    for i in range(len(my_list)-1) :
        if my_list[i] > my_list[i+1] :
            j = my_list[i]
            my_list[i] = my_list[i+1]
            my_list[i+1] = j


#5. 오름차순으로 정렬된 배열 출력
print("데이터 정렬 후 list : ", my_list)
