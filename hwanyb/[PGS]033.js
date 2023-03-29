function solution(angle) {
    return angle > 0 && angle < 90 ? 1 : angle === 90 ? 2 : angle > 90 && angle < 180 ? 3 : 4;
}



// filter와 length를 사용한 더 나은 방법
function solution(angle) {
    return [0, 90, 91, 180].filter(x => angle >= x).length;
}