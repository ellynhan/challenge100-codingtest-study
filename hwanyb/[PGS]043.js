function solution(numbers) {
    let max1 = Math.max(...numbers);
    if (numbers.join('').split(max1).length - 1 > 1) {
        return max1 * max1;
    } else {
        let max2 = Math.max(...numbers.filter(i => i !== max1));
        return max1 * max2;
    }
}

// 더 나은 풀이
function solution(numbers) {
    numbers.sort((a, b) => b - a);
    return numbers[0] * numbers[1];
}