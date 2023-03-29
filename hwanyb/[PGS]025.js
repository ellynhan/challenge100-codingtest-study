function solution(order) {
    const splitedOrder = order.toString().split("");
    let count = 0;

    for (let i = 0; i < splitedOrder.length; i++) {
        if (splitedOrder[i] === "3" || splitedOrder[i] === "6" || splitedOrder[i] === "9") {
            count += 1;
        }
    }
    return count;

}

// matchAll 메소드와 정규식을 사용한 방법
function solution(order) {
    var answer = [...order.toString().matchAll(/[3|6|9]/g)].length;
    return answer;
}