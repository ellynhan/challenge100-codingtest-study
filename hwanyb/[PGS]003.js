function solution(num, total) {
    // total을 num으로 나눈 값 (total의 중간값)
    // 구한 중간 값에서 num / 2의 내림처리 해서 구한 자릿수 값을 뺀다
    // 그 값을 올림처리해서 total의 초기값을 구한다
    const min = Math.ceil(total / num - Math.floor(num / 2));

    // Array.from 메소드를 이용해 길이가 num이고 초기값이 min인 배열을 반환
    return Array.from({ length: num }, (v, i) => i + min)
}