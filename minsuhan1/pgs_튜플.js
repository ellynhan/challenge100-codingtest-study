function solution(s) {
    let answer = [];
    // 숫자가 result에 들어갔으면 1 처리 (들어가기 전에는 0)
    const cache = Array.from({length: 1000000}, (v, i) => 0);
    // s를 2차원배열로 변환
    let arr = s.slice(2, -2).split("},{")
    arr = arr.map(v => v.split(","))
    // s를 집합 크기순으로 오름차순 정렬
    arr.sort((a, b) => a.length - b.length)
    // 집합 크기가 작은 것부터 안에 있는 숫자 중 cache처리되지 않은 숫자만 result에 넣고 cache처리
    arr.forEach(sub => sub.forEach(v => {
        const num = Number(v);
        if (cache[num] === 0) {
            cache[num] = 1;
            answer.push(num)
        }
    }))
    
    return answer;
}
