function solution(id_pw, db) {
    for (let i = 0; i < db.length; i++) {
        if (db[i][0] === id_pw[0]) { // id 동일
            if (db[i][1] === id_pw[1]) { // pw도 동일
                return "login";
            } else if (db[i][1] !== id_pw[1]) { // pw 틀림
                return "wrong pw";
            }
        }
    }
    return "fail";
}


// 비구조화 할당과 Map을 사용한 더 나은 풀이
function solution(id_pw, db) {
    const [id, pw] = id_pw;
    const map = new Map(db);
    return map.has(id) ? (map.get(id) === pw ? 'login' : 'wrong pw') : 'fail';
}