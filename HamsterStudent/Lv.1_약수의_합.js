function solution(n) {
    var answer = [];
    for(let i = 0; i < n; i++){
        if(n % i == 0){
            answer.push(i)
        }
    }
    return n + answer.reduce((acc,cur)=>acc + cur,0);
}
