function solution(n, numlist) {
    return numlist.filter((i) => Number.isInteger(i / n));
}