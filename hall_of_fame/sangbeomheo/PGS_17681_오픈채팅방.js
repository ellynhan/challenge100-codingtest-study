/*

프로그래머스 / 오픈채팅방 / 레벨 2
https://school.programmers.co.kr/learn/courses/30/lessons/42888

< 소요 시간 >
24분

< 프로그래밍 계획 >

1. record 배열을 순회한다.(1차)
- user의 id와 nickname을 계속 최신화한다. (Leave 제외)

2. record 배열을 순회한다.(2차)
- id, actionKR로 새로운 문자열 만들어 result배열에 추가 (Change 제외)

*/

function solution(records) {
  const user = {};
  const result = [];
  const actionKR = { Enter: "들어왔습니다.", Leave: "나갔습니다." };

  for (const record of records) {
    const [action, id, nickname] = record.split(" ");
    if (action === "Leave") continue;
    user[id] = nickname;
  }

  for (const record of records) {
    const [action, id, nickname] = record.split(" ");
    if (action === "Change") continue;

    result.push(`${user[id]}님이 ${actionKR[action]}`);
  }

  return result;
}
