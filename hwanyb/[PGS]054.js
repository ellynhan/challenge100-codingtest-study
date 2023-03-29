function solution(my_string) {
    return [...my_string].filter(i => !isNaN(i)).reduce((acc, curr) => acc + parseInt(curr), 0);
}