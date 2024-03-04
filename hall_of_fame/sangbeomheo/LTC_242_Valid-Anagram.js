/*

    LeetCode / Valid Anagram / Easy / 00:08:28
    https://leetcode.com/problems/valid-anagram/


    ## Pseudo Code ##

    s, t의 길이가 다르다면 애너그램x => return false
    s, t를 글자 단위로 쪼개 정렬한다.
    0번 index부터 비교해서 값이 다르면 애너그램 => return false
    비교를 통과했으면 애너그램 성립 => return true

*/

var isAnagram = function (s, t) {
  // s, t의 길이가 다르다면 애너그램 성립 x => return false
  if (s.length !== t.length) return false;

  // s, t를 글자 단위로 쪼개 정렬한다.
  const _s = s.split('').sort();
  const _t = t.split('').sort();

  // 0번 index부터 비교해서 값이 다르면 애너그램 성립 x => return false
  for (let i = 0; i < _s.length; i++) {
    if (_s[i] !== _t[i]) return false;
  }

  // 비교를 통과했으면 애너그램 성립 => return true
  return true;
};
