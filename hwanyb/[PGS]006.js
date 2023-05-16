function solution(my_str, n) {
    // my_str의 길이를 n으로 나눈 수를 올림처리
    // 위에서 구한 수를 길이로 갖는 배열 만듦 (newArr)
    let newArr = new Array(Math.ceil(my_str.length / n));

    // newArr의 i에
    // my_str의 i*n 부터 (i + 1) * n 전까지의 요소를 저장
    for (let i = 0; i < newArr.length; i++) {
        newArr[i] = my_str.slice(i * n, (i + 1) * n);
    }
    return newArr;
}