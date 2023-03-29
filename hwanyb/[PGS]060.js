function solution(numbers) {
    let multiple = [];
    for (let i = 0; i < numbers.length; i++) {
        for (let j = i + 1; j < numbers.length; j++) {
            multiple.push(numbers[i] * numbers[j]);
        }
    }
    return Math.max(...multiple);
}