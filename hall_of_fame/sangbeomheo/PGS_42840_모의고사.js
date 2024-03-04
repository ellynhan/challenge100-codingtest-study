/*

프로그래머스 / 모의고사 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/42840

< 소요 시간 >
51분

<프로그래밍 계획>
- 완전탐색
- 찍는 방식 3가지의 반복되는 패턴을 배열화
- answers를 각 패턴에 대입해서 가장 많이 맞춘 수포자 번호 리턴

*/

function solution(answers) {
  const pattern1 = [1, 2, 3, 4, 5];
  const pattern2 = [2, 1, 2, 3, 2, 4, 2, 5];
  const pattern3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];

  const a1 = answers.filter(
    (answer, index) => answer === pattern1[index % pattern1.length]
  ).length;
  const a2 = answers.filter(
    (answer, index) => answer === pattern2[index % pattern2.length]
  ).length;
  const a3 = answers.filter(
    (answer, index) => answer === pattern3[index % pattern3.length]
  ).length;
  const max = Math.max(a1, a2, a3);

  const result = [];
  a1 === max && result.push(1);
  a2 === max && result.push(2);
  a3 === max && result.push(3);

  return result;
}
