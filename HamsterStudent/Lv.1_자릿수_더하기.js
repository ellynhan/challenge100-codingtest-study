function solution(n)
{
    const str = String(n);
    const newArr = Array.from(str).map(Number);
    
    return newArr.reduce((acc,cur)=> acc + cur, 0);
}
