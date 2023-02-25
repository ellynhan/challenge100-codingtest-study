/*

프로그래머스 / 실패율 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/42889

< 소요 시간 >
35분

<프로그래밍 계획>
  1. stage 별로 도달한 유저 수를 표현할 배열 만들기 => 기본 유저 수 0
  2. stages를 순회하면서 도달 stage를 배열에 저장
  3. stage 별로 도달한 유저 수 배열을 순회
      - 실패율 구하기 : stage에 도달한 유저 수 / totalUser
      - totalUser에서 도달한 유저 수 빼기
  4. 실패율을 기준으로 스테이지 내림차순 정렬
  5. stage 번호만 담은 배열 반환

*/
function solution(N, stages) {
  const usersOnStages = Array(N).fill(0);
  for (const stage of stages) usersOnStages[stage - 1]++;

  let totalUser = stages.length;

  return usersOnStages
    .map((userCount, index) => {
      const failureRate = userCount / totalUser;
      totalUser -= userCount;
      return [index + 1, failureRate];
    })
    .sort((a, b) => b[1] - a[1])
    .map((stage) => stage[0])
    .slice(0, N);
}
