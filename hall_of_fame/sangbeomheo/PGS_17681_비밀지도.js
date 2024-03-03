/*

프로그래머스 / 비밀지도 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/17681

< 소요 시간 >
37분

< 프로그래밍 계획 >
  1. arr1, arr2를 이진수으로 변환한다.
  2. 변환된 이진수를 십진수 처럼 더한다.(arr1[0] + arr2[0])
  3. 0이면 "", 1 또는 2이면 "#" 으로 변환한다.

*/

function solution(n, arr1, arr2) {
  return Array(n)
    .fill(0)
    .map((_, i) => {
      let sumValue = String(Number(toBin(arr1[i])) + Number(toBin(arr2[i])));

      if (sumValue.length !== n)
        sumValue =
          Array(n - sumValue.length)
            .fill(0)
            .join("") + sumValue;

      return sumValue
        .split("")
        .map((value) => (Number(value) ? "#" : " "))
        .join("");
    });
}

function toBin(dex) {
  return dex.toString(2);
}
