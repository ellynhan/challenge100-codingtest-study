/*

    LeetCode / Valid Palindrome / Easy / 00:37:02
    https://leetcode.com/problems/valid-palindrome/


    ## Pseudo Code ##
    
    1. s를 _s로 변환한다.
        ㄴ 소문자로, 영숫자만 남김
        ㄴ toLowerCase(), charCodeAt()

    2. _s가 '' => true 리턴

    3. _s의 길이 / 2 만큼 반복문 실행
        ㄴ start인덱스와 end인덱스를 한칸씩 좁히면서 비교
        ㄴ 값이 다르면 => false 리턴

    4. 중간에 멈추지않고 반복문을 전부 돌았으면 => true 리턴


*/

var isPalindrome = function (s) {
  const _s = s
    .toLowerCase()
    .split('')
    .filter(
      char =>
        (char.charCodeAt() >= 48 && char.charCodeAt() <= 57) ||
        (char.charCodeAt() >= 97 && char.charCodeAt() <= 122)
    )
    .join('');

  if (_s.length === 0) {
    return true;
  }

  const endIndex = _s.length - 1;
  const repeatCount = Math.floor(_s.length / 2);

  for (let i = 0, j = endIndex; i < repeatCount; i++, j--) {
    if (_s[i] !== _s[j]) return false;
  }

  return true;
};
