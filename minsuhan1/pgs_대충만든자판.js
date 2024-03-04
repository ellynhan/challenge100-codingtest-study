function solution(keymap, targets) {
    let answer = [];
    const map = new Map();
    
    // 각 키에 할당된 문자들을 확인하며 모든 문자들의 최소 index(+1)를 Map 형태로 저장
    // Map에는 해당 문자를 위해 키를 최소 몇 번 눌러야 하는지 저장된다.
    keymap.forEach(key => {
        for(let i = 0; i < key.length; i++) {
            const char = key[i]
            const char_idx = map.get(char);
            if (char_idx !== undefined) {
                map.set(char, Math.min(char_idx, i+1));
            } else {
                map.set(char, i+1)
            }
        }
    })
    
    targets.forEach(target => {
        let count = 0;
        for(let i = 0; i < target.length; i++) {
            const char = target[i];
            const char_idx = map.get(char);
            if(char_idx === undefined) {
                count = -1;
                break;
            } else {
                count += char_idx
            }
        }
        answer.push(count)
    })
    
    return answer;
}
