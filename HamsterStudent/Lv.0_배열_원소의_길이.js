function solution(strlist) {
    var answer = [];
    strlist.map((x)=>{
        let arr = [...x]
        answer.push(arr.length)
    })
    return answer;
}
