function solution(numbers) {
    let arr = [0,1,2,3,4,5,6,7,8,9]
    numbers.sort()
    let answer = arr.filter(x=> !numbers.includes(x))
    return answer.reduce((acc,cur)=> acc + cur, 0);
}
