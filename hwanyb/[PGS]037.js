function solution(n, k) {
    const 양꼬치값 = n * 12000;
    const 음료수값 = (k - (Math.floor(n / 10))) * 2000;
    return 양꼬치값 + 음료수값;
}