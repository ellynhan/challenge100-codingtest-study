function solution(s, skip, index) {
    let answer = '';
    // a: 97, z: 122
    [...s].forEach(char => {
        let next = char.charCodeAt(0)
        // 한 글자씩 뒤의 알파벳으로 바꾸면서 (횟수는 index만큼)
        // skip 문자가 되는경우 한 번 더 뒤의 알파벳으로 바꾼다
        // 'z'를 넘어가면 'a'로 돌아가도록 처리했다
        for(i = 0; i < index; i++) {
            next += 1;
            if(next > 122)
                next -= 26;

            while(skip.includes(String.fromCharCode(next))) {
                next += 1;

                if(next > 122)
                    next -= 26;
            }
        }
        
        answer += String.fromCharCode(next);
    });
    
    return answer;
}
