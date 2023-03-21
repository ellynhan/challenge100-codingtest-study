function solution(A, B) {
    // A와 B가 같을 시 문자열을 밀지 않아도 되므로 0 반환
    if (A === B) return 0;

    let arr = [...A]; // A를 배열로 변환

    for (let i = 0; i < arr.length; i++) {
        // arr의 마지막 요소를 빼 맨 앞에 위치 시키면
        // 한 칸 민 것이므로 인덱스 + 1 반환
        arr.unshift(arr.pop());
        if (arr.join('') === B)
            return i + 1;
    }
    // A를 B로 만들 수 없다면 -1 반환
    return -1;
}