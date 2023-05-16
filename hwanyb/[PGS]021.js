function solution(my_string, num1, num2) {
    let arr = [...my_string];

    const str1 = arr[num1];
    const str2 = arr[num2];

    arr[num1] = str2;
    arr[num2] = str1;

    return arr.join('');
}

// 비구조화 할당을 사용한 더 간단한 방법
function solution(my_string, num1, num2) {
    let arr = [...my_string];

    [arr[num1], arr[num2]] = [arr[num2], arr[num1]];

    return arr.join('');
}