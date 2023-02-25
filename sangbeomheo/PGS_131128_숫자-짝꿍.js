/*

프로그래머스 / 숫자 짝꿍 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/131128

< 소요 시간 >
40분

*/

function solution(X, Y) {
  const _X = [...X];
  const _Y = [...Y];

  const numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'];
  let commonNumbers = '';

  numbers.forEach(number => {
    const amountX = _X.filter(v => v === number).length;
    const amountY = _Y.filter(v => v === number).length;
    const commonAmount = Math.min(amountX, amountY);

    if (commonAmount) {
      commonNumbers += number.repeat(commonAmount);
    }
  });

  if (commonNumbers.length === 0) return '-1';

  if (Number(commonNumbers) === 0) return '0';

  return [...commonNumbers].sort((a, b) => b - a).join('');
}
