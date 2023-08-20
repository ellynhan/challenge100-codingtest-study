const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().split('\n').map(Number);


// 골드바흐의 추측 :주어진 짝수 정수 n에 대해서, n을 두 소수의 합으로 나타내는 방법을 찾는 알고리즘
//1. 주어진 짝수 정수 n을 입력 받습니다.
//2. 2부터 n까지의 모든 소수를 구합니다. (에라토스테네스의 체 등의 방법을 사용하여 소수를 구할 수 있습니다.)
//3. n을 두 소수의 합으로 나타낼 때, 두 소수의 조합을 찾습니다.
//4. 소수 i를 첫 번째 소수로 선택하고, (n - i)가 소수인지 검사합니다.
//5. n - i가 소수라면, i와 n - i가 n의 두 소수 합으로 나타낼 수 있습니다.
//6. 이런 조합을 찾을 때까지 i를 증가시키며 검사합니다.
//7. n의 두 소수 합 조합을 출력하거나 저장합니다.

let ans = "";
// 주어진 수보다 작은 소수 중에 가장 큰 수 찾기
const max = Math.max(...input); // 42

const  isPrime = new Array(max + 1).fill(true);

isPrime[0] = false;
isPrime[1] = false;


for (let i = 2; i * i <= max; i++) {
  if (isPrime[i]) {
      for (let j = i * i; j <= max; j += i) {
          isPrime[j] = false;
      }
  }
}


input.map( (n) =>{
  for(let i = 3; i <= n; i++){

    if(isPrime[i] && isPrime[n - i]){
      ans += `${n} = ${i} + ${n - i}\n`;
      break;
    }
  }
});
console.log(ans);