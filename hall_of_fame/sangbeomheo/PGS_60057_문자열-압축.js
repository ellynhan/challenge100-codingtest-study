/*

프로그래머스 / 문자열 압축 / 레벨 2
https://school.programmers.co.kr/learn/courses/30/lessons/60057


    1. 문자열을 1 ~ 문자열길이/2 단위로 잘라 배열을 만든다
    2. result에 연속된 중복 요소의 개수가 (1 => 1, 2이상 => 2) 더한다.
    3. result 리턴

< 소요 시간 >
1시간 50분

< 프로그래밍 계획 >

  1.  문자열을 1 ~ 문자열길이/2 단위로 잘라 배열을 만든다.
  2. 변수 설정 : 압축한문자열 => str = "", 중복카운트 => count = 1
  3.  배열의 요소를 체크
      - 요소와 다음 요소가 같다면 count++
      - 요소와 다음 요소가 다르다면 str에 요소를 더함
        - 더할 때 count가 1이면 요소만, count가 1이 아니면 (count + 요소)를 더함
  4. 제일 길이가 짧은 요소의 길이 반환
*/

function solution(s) {
  if (s.length === 1) return 1;

  let shortest = Number.MAX_SAFE_INTEGER;

  for (let i = 1; i <= s.length / 2; i++) {
    const arr = [];

    for (let j = 0; j < s.length; j += i) arr.push(s.slice(j, j + i));

    let str = "";
    let duplicateCount = 1;

    arr.forEach((value, index) => {
      if (value !== arr[index + 1]) {
        duplicateCount === 1 ? (str += value) : (str += duplicateCount + value);
        duplicateCount = 1;
      } else {
        duplicateCount++;
      }
    });

    shortest = shortest < str.length ? shortest : str.length;
  }

  return shortest;
}
