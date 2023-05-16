function solution(my_string) {
    let arr = [...my_string];
    for (let i = 0; i < arr.length; i++) {
        if (arr[i].charCodeAt() >= 65 && arr[i].charCodeAt() <= 90) {
            arr[i] = arr[i].toLowerCase();
        } else {
            arr[i] = arr[i].toUpperCase();
        }
    }
    return arr.join('');
}


// map과 삼항연산자를 사용한 더 간단한 방법
function solution(my_string) {
    return [...my_string].map(c => c.charCodeAt() >= 65 && c.charCodeAt() <= 90 ? c.toLowerCase() : c.toUpperCase()).join('');
}
