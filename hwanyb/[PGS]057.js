function solution(hp) {
    let count = Math.floor(hp / 5);
    let remain = hp - 5 * count;
    if (remain === 4 || remain === 2) {
        count += 2;
    } else if (remain === 3 || remain === 1) {
        count += 1;
    }
    return count;
}

// 나머지 값을 활용한 방법
function solution(hp) {
    return Math.floor(hp / 5) + Math.floor((hp % 5) / 3) + (hp % 5) % 3;
}