function solution(num) {
    var answer = num;
    let count = 0;
    while(answer !== 1){
        if(answer % 2 != 0){
            answer = (answer * 3) + 1
        }else{
            answer = answer / 2
        }
        count++
    }
    return count < 500 ? count : -1;
}
