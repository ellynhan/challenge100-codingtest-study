function solution(numbers) {
    return Number(numbers.replaceAll('zero', 0).replaceAll('one', 1).replaceAll('two', 2).replaceAll('three', 3).replaceAll('four', 4).replaceAll('five', 5).replaceAll('six', 6).replaceAll('seven', 7).replaceAll('eight', 8).replaceAll('nine', 9));
}

// 정규식을 사용한 방법
function solution(numbers) {
    const numberMap = {
        'zero': 0,
        'one': 1,
        'two': 2,
        'three': 3,
        'four': 4,
        'five': 5,
        'six': 6,
        'seven': 7,
        'eight': 8,
        'nine': 9
    };
    return Number(numbers.replace(/(zero|one|two|three|four|five|six|seven|eight|nine)/g, match => numberMap[match]));
}