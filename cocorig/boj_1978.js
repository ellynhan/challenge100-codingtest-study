const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n')

const list =  input[1].split(' ').map(Number);//[ 1, 3, 5, 7 ]

function isPrime(num){

    if(num === 1) return false; // 1은 소수가 아님
    for(let i = 2; i <= parseInt(Math.sqrt(num)); i++){
      if(num  % i === 0 ) return false;
      // 다른 수와 나누어 떨어진다면 소수가 아님
    }
    return true;
  }



console.log(list.filter(item => isPrime(item)).length);


