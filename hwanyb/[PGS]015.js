function solution(num, k) {
    return num.toString().includes(k.toString()) ? num.toString().indexOf(k.toString()) + 1 : -1;
}