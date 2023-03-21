function solution(dot) {
    const [x, y] = dot;
    if (x < 0) { // x가 음수인 경우
        return y < 0 ? 3 : 2;
    } else { // x가 양수인 경우
        return y < 0 ? 4 : 1;
    }
}