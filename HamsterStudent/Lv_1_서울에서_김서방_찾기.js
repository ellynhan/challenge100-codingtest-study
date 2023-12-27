function solution(seoul) {
    let answer = ""
    seoul.map((x,idx)=> {
        if(x === "Kim"){
            answer = `김서방은 ${idx}에 있다`
        }
    });
    return answer
} 
