function solution(money) {
    const americano = Math.floor(money / 5500);
    const remain = money - (americano * 5500);

    return [americano, remain];
}


// 더 멋진 풀이
function solution(money) {
    return [Math.floor(money / 5500), money % 5500];
}