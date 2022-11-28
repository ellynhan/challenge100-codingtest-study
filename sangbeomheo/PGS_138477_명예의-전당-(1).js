/*

프로그래머스 / 명예의 전당 (1) / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/138477

< 소요 시간 >
17분

*/

function solution(k, scores) {
  const honor = [];

  return scores.map(score => {
    if (honor.length < k) {
      // 명에의 전당 자리가 빈 경우
      honor.push(score);
    } else if (score > Math.min(...honor)) {
      // 명에의 전당 자리가 전부 찬 경우
      honor.push(score);
      honor.sort((a, b) => b - a);
      honor.pop();
    }

    return Math.min(...honor);
  });
}
