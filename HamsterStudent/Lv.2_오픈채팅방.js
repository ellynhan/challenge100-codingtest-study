function solution(record) {
    let answer = []
    var array = record.slice();
    let user = {}
    let log = {}
    
    array.map((x,idx)=>{
        let arr = x.split(' ')
        user[`${arr[1]}`] = arr[2]
        log[idx] = { status : arr[0], id : arr[1], name : arr[2]}
    })

    for(let item in user){
        for(let x in log){
            if(item === log[x].id){
                log[x].name = user[item]
            }
        }
    }
    
    for(let y in log){
        if(log[y].status !== "Change"){
            answer.push(`${log[y].name}님이 ${log[y].status === "Enter" ? "들어왔습니다." : "나갔습니다."}`)
        }
    }
    
    return answer;
}
