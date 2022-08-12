/*

프로그래머스 / 소수 만들기 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12977

< 소요 시간 >
19분

<프로그래밍 계획>
  - 숫자 3개를 고르는데 순서 상관 없는 모든 경우 찾기
  - 숫자 3개를 더한 값이 소수라면 count++
  - count 리턴

  - 소수판별 함수 따로 빼서 사용
*/

function solution(nums) {
  const length = nums.length;
  let count = 0;

  for (i = 0; i < length - 2; i++) {
    for (j = i + 1; j < length - 1; j++) {
      for (k = j + 1; k < length; k++) {
        console.log(nums[i], nums[j], nums[k]);
        const candidate = nums[i] + nums[j] + nums[k];
        isPrime(candidate) && count++;
      }
    }
  }

  return count;
}

function isPrime(number) {
  if (number < 2) return false;

  for (let i = 2; i <= Math.floor(Math.sqrt(number)); i++) {
    if (number % i === 0) return false;
  }

  return true;
}
