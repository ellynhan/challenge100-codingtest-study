function solution(s) {
    let arr = s.split(' ')
    let newArr = arr.map(Number)
    
    newArr.sort((x,y) => (x - y));
    newArr.splice(1, newArr.length - 2)
    return newArr.join(' ');
}
