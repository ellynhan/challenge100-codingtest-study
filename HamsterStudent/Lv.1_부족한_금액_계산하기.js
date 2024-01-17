function solution(price, money, count) {
    var answer = -1;
    let number = 0
    let wallet = money
    while(number != count){
        wallet = wallet - (price * number)
        number++
    }
    answer = (price * number) - wallet
    return answer < 0 ? 0 : answer;
}
