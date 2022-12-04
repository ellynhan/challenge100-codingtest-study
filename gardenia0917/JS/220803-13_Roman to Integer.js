/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function (s) {
  //s는 로마 문자
  // 심볼에 맞춰서 숫자를 선언해준다.

  const roman = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000,
  };

  // 답 선언 미리해주기
  let result = 0;

  // 왼쪽이 큰 숫자이고 오른쪽으로 갈수록 일의 자리 숫자
  // IV, IX, XL, XC, CD, CM 의 경우는 앞자리 - 뒷자리 = 숫자 가 된다.
  // 반복문을 돌려주면서,
  for (let i = 0; i < s.length; i++) {
    let front = roman[s[i]]; // 앞 자리
    let back = roman[s[i + 1]]; // 뒷 자리
    // 뒷자리가 크면 앞자리-뒷자리
    if (back > front) {
      result += front - back;
      i++;
    }
    // 앞자리가 크면 심볼에 맞춰진 숫자를 넣고,
    else {
      result += front;
    }
  }
  return result;
};
