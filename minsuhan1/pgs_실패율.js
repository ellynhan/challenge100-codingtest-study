function solution(N, stages) {
    let answer = [];
    // 실패율 구하기
    for (let i = 1; i <= N; i++) {
        const challengers = stages.filter(stage => stage >= i).length;
        const winners = stages.filter(stage => stage === i).length;
        if (challengers === 0) {
            answer.push([0, i])
        } else {
            answer.push([winners / challengers, i])
        }
    }
    
    // 다중 조건 정렬
    answer.sort((a, b) => (b[0] - a[0]) || (a[1] - b[1]));
    return answer.map(v => v[1]);
}
