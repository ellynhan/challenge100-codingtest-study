function solution(X, Y) {
    let answer = '';
    const x_arr = X.split("");
    const y_arr = Y.split("");
    const x_count_arr = new Array(10).fill(0);
    const y_count_arr = new Array(10).fill(0);
    
    // X, Y에 0~9가 각각 몇개들어있는지 카운트
    x_arr.forEach(x => x_count_arr[x] += 1);
    y_arr.forEach(y => y_count_arr[y] += 1);
    
    // X, Y에 모두 들어있는 숫자라면 카운트가 작은횟수만큼 answer에 추가
    for(let i = 0; i <= 9; i++) {
        if(x_count_arr[i] > 0 && y_count_arr[i]) {
            answer += i.toString().repeat(Math.min(x_count_arr[i], y_count_arr[i]));
        }
    }
    
    // 예외처리
    if(answer.length === 0) {
        return '-1';
    } else if(answer.length > 0 && +answer === 0) {
        return '0';
    // 내림차순정렬 후 출력
    } else {
        return answer.split('').reverse().join('');
    }
}
