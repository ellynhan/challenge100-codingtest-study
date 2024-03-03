// 문자열을 입력받아서, 같은 문자가 연속적으로 반복되는 경우에 그 반복 횟수를 표시하여 문자열을 압축하기.

// 입력 예시: aaabbcccccca

// 출력 예시: a3b2c6a1


function solution(input) {
  // 1. 반복문 사용
  // let ans = '';
  // let cnt = 1;

  // for (let i = 0; i < input.length; i++) {

  //   if (input[i] === input[i + 1]) {
  //     cnt++;
  //   } else { 
  //     ans += input[i] + cnt;
  //     cnt = 1; // 여기서 cnt 초기화
  //   }
  // }
  // return ans;

  // 2. 정규식 표현식 사용
  const reg = /(\w)\1*/g;
  return input.replace(reg, (v, char) => 
  // console.log(v.length, char)
    char + v.length
  );

}
// aaa a
// bb b
// cccccc c
// a a


// 테스트
const result = solution('aaabbcccccca');
console.log(result); // 출력 예시: "a3b2c6a1"



