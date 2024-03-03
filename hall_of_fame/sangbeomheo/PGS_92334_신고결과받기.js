/*

프로그래머스 / 신고 결과 받기 / 레벨 1
https://programmers.co.kr/learn/courses/30/lessons/92334

< 소요 시간 >
50분

< 프로그래밍 계획 >
  - 코드에 주석으로 작성함
  
*/

function solution(id_list, report, k) {
  const reportInfo = {}; // id, id가 신고한 유저정보(중복제거)
  const reportCount = {}; // 유저별로 신고당한 수
  const suspended = []; // 이용정지 된 유저 id

  // reportInfo 구하기 { id : Set {id가 신고한 유저id}, ... }
  id_list.forEach((id) => (reportInfo[id] = new Set()));
  report.forEach((value) => {
    const [reporter, reported] = value.split(" ");
    reportInfo[reporter].add(reported);
  });

  // reportCount 구하기 { id: count, ... }
  for (const reporteds of Object.values(reportInfo)) {
    for (let reported of reporteds) {
      reportCount[reported]
        ? (reportCount[reported] += 1)
        : (reportCount[reported] = 1);
    }
  }

  // suspended 구하기
  for (const [id, count] of Object.entries(reportCount)) {
    count >= k && suspended.push(id);
  }

  if (!suspended.length) {
    return id_list.map((id) => 0);
  }

  const answer = [];

  for (const [reporter, reporteds] of Object.entries(reportInfo)) {
    let count = 0;
    for (let reported of reporteds) {
      suspended.includes(reported) && count++;
    }
    answer.push(count);
  }

  return answer;
}
