const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().split(' ').map(Number);

let a = Math.max(...input)
let b = Math.min(...input)


function getGCD(a,b){
  let r = 0;
  while(b !== 0){
    r  =  a % b;
    a = b;
    b = r;
  }
  return a;
}
console.log(getGCD(a ,b)); // 최대공약수


function getLCM(a,b){
  let g = getGCD(a,b);
  return (a * b) / g ;
}
console.log(getLCM(a,b)); // 최소공배수
 
