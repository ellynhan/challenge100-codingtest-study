function solution(food) {
    var answer = [];
    food.map((x,idx)=>{
        let temp
        if(x % 2 !== 0){
            temp = (x - 1) / 2
        }else{
            temp = (x / 2)
        }
        for(let i = 0; i < temp; i++){
           answer.push(idx)
       }
    })
    const reverse = [...answer,0].reverse()
    answer.push(reverse)
    
    return answer.join().replaceAll(",","");
}
