function solution(my_string) {
    return [...my_string].filter(i => !isNaN(parseInt(i))).map(i => parseInt(i)).sort();
}