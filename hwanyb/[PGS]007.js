function solution(array) {
    const splitedArr = [...array.join('')];
    
    let count = 0;

    for (let i = 0; i < splitedArr.length; i++) {
        if (splitedArr[i] === "7") {
            count += 1;
        }
    }
    return count;
}