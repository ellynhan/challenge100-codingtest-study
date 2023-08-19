const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().trim().split('\n').map(Number);


// 통과
for(let i = 0; i < input.length; i++){
  let num  = '1';
  let remainder = 1 % input[i];
  while(remainder !== 0){
    num += '1';
    remainder = (remainder * 10 + 1) % input[i];

  }
  console.log(num.length);
}




//  시간 초과 코드
for(let i = 0; i < input.length; i++){
  let num  = '1';
  let remainder = 1 % input[i];
  while(remainder !== 0){
    num += '1';
    remainder =  Number(num) % input[i];

  }
  console.log(num.length);
}

// 시간 초과가 나는 이유?
//내부 반복문: 내부 while 루프에서는 num이라는 문자열을 점점 늘려가며 나머지 연산을 수행했다.
// 이 과정에서 num을 숫자로 변환하고 나머지 연산을 계속 반복. 이 때 num의 길이가 계속 늘어나므로, 숫자 변환과 나머지 연산도 시간이 소요될 수 있다.

// 1 % 3 = 1
// 11 % 3 = 2 
// 111 % 3 = 0 0일때 111은 3의 배수가 된다

// 1 % 7 = 1
// 11( 1 * 10 + 1 ) % 7 = 4
// 111(4 * 10 + 1) % 7 = 6
// 1111(6 * 10 + 1) % 7 = 5
// 11111(5 * 10 + 1) % 7 = 2
// 111111(2 * 10 + 1) % 7 = 0 -> 111111이 7의 배수

// 나머지 연산 최적화
// 모듈러 연산을 활용하여 나머지를 계산함
// 이렇게 하면 나머지 연산의 효율성이 증가하게 된다.

