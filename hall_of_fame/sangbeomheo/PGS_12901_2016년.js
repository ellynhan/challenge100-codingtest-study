/*

프로그래머스 / 2016년 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12901

< 소요 시간 >
13분

<프로그래밍 계획>
  - getDay()로 요일 인덱스 구하기
*/

function solution(a, b) {
  const month = String(a).length === 1 ? 0 + String(a) : String(a);
  const date = String(b).length === 1 ? 0 + String(b) : String(b);
  const week = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"];
  const dayIndex = new Date(`2016-${month}-${date}`).getDay();

  return week[dayIndex];
}
