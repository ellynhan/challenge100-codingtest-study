function solution(my_string, n) {
    return [...my_string].map(i => i.repeat(n)).join("");
}