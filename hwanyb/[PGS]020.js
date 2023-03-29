function solution(s) {
    let answer = [];

    s.split('').forEach((i) => {
        if (s.indexOf(i) === s.lastIndexOf(i)) {
            answer.push(i);
        }
    });
    return answer.sort().join('');
}