function solution(board, moves) {
    let answer = 0;
    const blanket = [];
    N = board.length;
    moves.forEach(move => {
        let pick = 0;
        for(i = 0; i < N; i++) {
            // 가장 위에 있는 인형을 뽑고 blank처리
            pick = board[i][move-1] || 0;
            if(pick > 0) {
                board[i][move-1] = 0;
                break;
            }
        }
        // 뽑은 인형이 있는경우
        if (pick > 0) {
            // 밑에 인형이 있으면 해당 인형을 제거하고 인형을 넣지 않는다.
            if (blanket.length > 0 && blanket.at(-1) === pick) {
                blanket.pop();
                answer += 2;
            } else {
                blanket.push(pick);
            }
        }
    })
    
    return answer;
}
