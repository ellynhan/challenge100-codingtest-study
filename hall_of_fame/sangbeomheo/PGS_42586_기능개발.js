/*

프로그래머스 / 기능개발 / 레벨 2
https://school.programmers.co.kr/learn/courses/30/lessons/42586

< 소요 시간 >
58분

< 프로그래밍 계획 >
  1. 작업 순서대로 작업 일 수를 구해 배열화 한다.
    - ((100 - 작업 진도) / 작업 속도) => 올림처리
  2. 작업 일 수 배열을 순회하면서 체크

*/

function solution(progresses, speeds) {
  const remindDays = progresses.map((progress, index) => {
    return Math.ceil((100 - progress) / speeds[index]);
  });

  const answer = [0];
  let maxDay = remindDays[0];

  remindDays.forEach((day) => {
    if (day > maxDay) {
      maxDay = day;
      answer.push(1);
    } else {
      answer[answer.length - 1] += 1;
    }
  });

  return answer;
}
