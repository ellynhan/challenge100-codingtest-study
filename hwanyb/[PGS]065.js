function solution(emergency) {
    const sortedArr = emergency.slice().sort((a, b) => b - a);

    let map = {};
    for (let i = 0; i < emergency.length; i++) {
        map[sortedArr[i]] = i + 1
    }
    return emergency.map(v => map[v]);
}

// sortedArr와 같이 배열을 정렬할 때, 원본배열이 수정되지 않도록 slice() 메소드를 사용할 것