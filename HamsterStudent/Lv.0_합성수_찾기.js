function solution(n) {
    var answer = 0;
    
    for(let i = 0; i <= n; i++){
        let count = 0
        for(let j = 1; j <= i; j++){
            if(i % j === 0){
                count++
            }
        }
        if(count > 2){
            answer++
            count = 0
        }
    }
    return answer;
}
