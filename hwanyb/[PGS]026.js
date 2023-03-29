function solution(array, n) {
    let diffArr = [];
    let closestIdArr = [];

    // array의 요소와 n의 차이를 diffArr에 저장
    for (let i = 0; i < array.length; i++) {
        diffArr[i] = Math.abs(array[i] - n);
    };

    // diffArr에서 가장 작은 수를 min에 저장
    let min = Math.min(...diffArr);

    // diffArr의 요소와 min을 비교하며 min과 요소가 같으면
    // 해당 인덱스 값을 closestIdArr 에 push
    for (let j = 0; j < diffArr.length; j++) {
        if (diffArr[j] === min) {
            closestIdArr.push(j);
        }
    };

    // 만약 closestIdArr의 길이가 1이면
    // n과 min만큼 차이나는 수가 1개이므로
    // diffArr에 min이 위치하는 인덱스를 찾아 array의 해당 인덱스 값을 반환
    if (closestIdArr.length === 1) {
        return array[diffArr.indexOf(min)];
    } else {
        // closestIdArr의 길이가 1보다 클 시
        // n과 min만큼 차이나는 수가 2개 이상이기 때문에 더 작은 수를 반환하기 위해
        // closestIdArr에 담긴 인덱스 반복문으로 돌며
        // 그 수중 작은 수를 반환
        for (let k = 0; k < closestIdArr.length; k++) {
            return Math.min(array[closestIdArr[k]], array[closestIdArr[k + 1]]);
        }
    }
}






// reduce 메소드와 삼항연산자를 사용한 방법
function solution(array, n) {
    return array.reduce((a, c) => Math.abs(a - n) < Math.abs(c - n) ? a : Math.abs(a - n) === Math.abs(c - n) ? Math.min(a, c) : c);
}