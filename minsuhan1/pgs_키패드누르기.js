function solution(numbers, hand) {
    let answer = '';
    
    let l = '*';
    let r = '#';
    
    const map = new Map([['*',0], [7,1], [4,2], [1,3], [0,0], [8,1], [5,2], [2,3], ['#',0], [9,1], [6,2], [3,3]]);
    const larr = ['*',7,4,1];
    const marr = [0,8,5,2];
    const rarr = ['#',9,6,3];
    
    numbers.forEach(num => {
        if (larr.includes(num)) {
            answer += 'L';
            l = num;
        } else if (rarr.includes(num)) {
            answer += 'R';
            r = num;
        } else {
            let ld = Math.abs(map.get(num) - map.get(l))
            let rd = Math.abs(map.get(num) - map.get(r))
            if (!marr.includes(l)) ld += 1;
            if (!marr.includes(r)) rd += 1;
            
            if (ld < rd) {
                answer += 'L';
                l = num;
            } else if (ld > rd) {
                answer += 'R';
                r = num;
            } else {
                if (hand === 'left') {
                    answer += 'L';
                    l = num;
                } else {
                    answer += 'R';
                    r = num;
                }
            }
        }
    })
    return answer;
}
