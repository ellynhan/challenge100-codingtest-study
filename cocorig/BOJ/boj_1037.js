const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().split('\n')



let divisor =input[1].split(' ').map(item => {
    return Number(item);
}).sort((a , b) => a - b); 
// console.log(divisor);// [ 2, 4 ]


function getDivisor(divisor){

  let minDivisor = Math.min(...divisor);
  let maxDivisor = Math.max(...divisor);
  const N = minDivisor * maxDivisor;
  return N;
}
const result  = getDivisor(divisor)
console.log(result);

// 입력받은 약수 배열을 정렬한다
// 작은수와 큰수를 곱한다

