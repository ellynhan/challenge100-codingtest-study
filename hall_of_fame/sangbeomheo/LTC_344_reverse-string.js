/*

    LeetCode / Reverse String / Easy / 00:03:42
    https://leetcode.com/problems/reverse-string/


    ## Pseudo Code ##
    
    투포인터를 이용해 앞뒤로 매칭된 요소를 스위치한다.

    1. for 반복문
        ㄴ 투포인터(인덱스) 설정. 
        ㄴ 시작점: i = 0, j = lastIndex - i
        ㄴ 배열의 i번째 요소와 j번째 요소를 스위치

*/

var reverseString = function (s) {
  const lastIndex = s.length - 1;
  const repeat = Math.floor(s.length / 2);

  for (let i = 0; i < repeat; i++) {
    let j = lastIndex - i;
    [s[i], s[j]] = [s[j], s[i]];
  }
  return s;
};
