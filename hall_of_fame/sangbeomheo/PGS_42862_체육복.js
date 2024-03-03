/*

프로그래머스 / 체육복 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/42862

< 소요 시간 >
45분 

< 프로그래밍 계획 >
    답: n - 체육복을 못 빌린 학생 수
    
    못 빌린 학생은
    1. 여벌을 가져왔는데 도난당했으면 제외
    2. lost 학생 번호의 앞 뒤로 reserve번호 있으면 제외
    3. 최종 남은 lost가 체육복 못빌린 학생 수
  
*/

function solution(n, losts, reserve) {
  let [_losts, _reserve] = [losts, reserve];

  losts.forEach((lost, index) => {
    if (reserve.includes(lost)) {
      _reserve.splice(reserve.indexOf(lost), 1);
      _losts[index] = 0;
    }
  });

  _losts = _losts.filter((lost) => lost !== 0);

  _losts.sort((a, b) => a - b);
  _reserve.sort((a, b) => a - b);

  let count = _losts.length;

  if (count === 0) return n;

  for (const lost of _losts) {
    if (reserve.includes(lost - 1)) {
      _reserve.splice(_reserve.indexOf(lost - 1), 1);
      count--;
      continue;
    }
    if (reserve.includes(lost + 1)) {
      _reserve.splice(_reserve.indexOf(lost + 1), 1);
      count--;
      continue;
    }
  }

  return n - count;
}
