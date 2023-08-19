const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().split(' ').map(Number);
// console.log(input);

const M = input[0];
const N = input[1];


//M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

// 1 . 반복문 (시간복잡도 O(n)) 가장 기본적인 방법 (빈복문을 수행하면서 1이외의 수로 나누어 떨어지지 않는지 확인) -> 시간 초과

// function isPrime(num){
//   if(num === 1) return false; // 1은 소수가 아님
//   for(let i = 2; i  < num; i++){
//     if(num  % i === 0 ) return false;
//     // 다른 수와 나누어 떨어진다면 소수가 아님
//   }
//   return num; // 반복문 종료할때까지 if문이 실행되지 않았다면 소수
// }

// for(let i = M; i <= N; i++) {
//   if(isPrime(i)){
//     console.log(isPrime(i));
//   }
// }

// 2. 반복문 최적화 num의 제곱근까지만 반복하기 


function isPrime(num){
  if(num === 1) return false; // 1은 소수가 아님
  for(let i = 2; i <= parseInt(Math.sqrt(num)); i++){
    if(num  % i === 0 ) return false;
    // 다른 수와 나누어 떨어진다면 소수가 아님
  }
  return num; // 반복문 종료할때까지 if문이 실행되지 않았다면 소수
}

for(let i = M; i <= N; i++) {
  if(isPrime(i)){
    console.log(isPrime(i));
  }
}


