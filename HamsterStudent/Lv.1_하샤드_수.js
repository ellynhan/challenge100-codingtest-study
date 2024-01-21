function solution(x) {
    const str = String(x);
    const newArr = Array.from(str).map(Number);
    const num = newArr.reduce((acc,cur)=>acc+cur,0)

    return x % num === 0 ? true : false
}
