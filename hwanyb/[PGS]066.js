function solution(my_string) {
    return my_string.split(/[a-z|A-Z]/).filter(i => i !== "").map(i => Number(i)).reduce((acc, curr) => acc + curr, 0);
}

// 문자열에 숨어있는 숫자를 더해 반환하는 문제
// 제한 사항에 문자열에 자연수가 없는 경우 0을 return 해주세요.
// reduce 초기값으로 0을 지정해주지 않으면
// 8번 테스트에서 런타임에러 발생
// reduce메소드를 사용할 때에는 초기값을 지정해주자