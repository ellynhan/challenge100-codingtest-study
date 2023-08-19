const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString();

const N = parseInt(input);

//** g(N)약수의 합 구하기
// 약수의 반대 개념인 배수로 풀어야 한다!!! 배수의 개수 == 약수를 가진 값들 개수
// 1.  1 ~ 7의 수 중 배수의 개수 구하기
//  1~7까지의 수 중 1의 배수의 개수는 ? ( 7 / 1 ) 은 7 
// 2의 배수의 개수는 ->(7 / 2 ) 는 ? 3. 5
// 3의 배수의 개수는  -> (7 / 3 ) -> 2.3333

// 2. 이 약수들의 합을 구함
//  1 ~ 7의 수 중  1을 약수로 갖는 수의 개수가 7개라는 것.
//  2의 약수로 갖는 수의 개수가 3개라는 것
//  2 * (2를 약수로 갖는 수의 개수) =>  6  , 2가 3개 있다는 뜻이므로 2 * 3을 해줘야함
//  3 * (3을 약수로 갖는 수의 개수 ) => 6
//  약수를 갖는 값들의 개수이므로 해당 수와 곱해야함
let sum = 0;

  for(let i = 1; i <= N; i++){
    //                    (N / i ) ->  i의 배수의 개수를 구하는 식
    sum += i * Math.floor((N) / i);
    }

console.log(sum);






// 시간 초과 코드 
// let result = 0;
// function getDivisor(n){

//   for(let i = 1; i <= n; i++){
   
//     for(let j = 1; j <= i; j++){
//     if( i % j === 0){
//       result += j;
//     }
//   }
  
// }
//     return result;
// }
// const ans  =  getDivisor(N);
// console.log(ans);

