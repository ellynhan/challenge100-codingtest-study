function solution(participant, completion) {
    let answer = '';
    const hashMap = new Map();
    // 참가자 value += 1
    // 완주자 value -= 1
    participant.forEach(p => hashMap.set(p, (hashMap.get(p) || 0) + 1))
    completion.forEach(c => hashMap.set(c, hashMap.get(c) - 1))
    
    // 완주하지 못한 사람의 value == 1
    for(let [key, value] of hashMap) {
        if(value === 1) {
            answer = key;
        }
    };
    
    return answer;
}
