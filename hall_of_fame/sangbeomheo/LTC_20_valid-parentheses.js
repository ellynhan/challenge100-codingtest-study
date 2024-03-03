/*

    LeetCode / Valid Parentheses / Easy / 01:22:21
    https://leetcode.com/problems/valid-parentheses/


    ## Pseudo Code ##
    
    1. 배열 스택 생성 []

    2. 반복문 for..of로 s를 하나씩 탐색
        ㄴ 스택의 길이가 0 && 둘 다 왼쪽이면 => push
        ㄴ isMatch이면 => pop
        ㄴ 나머지 => return false

    3. 남은 스택의 길이 확인
        ㄴ 0 => true
        ㄴ 0보다 크면 => false

*/

var isValid = function (s) {
  const stack = [];

  const brackets = {
    '{': { shape: 1, direction: 'left' },
    '[': { shape: 2, direction: 'left' },
    '(': { shape: 3, direction: 'left' },
    '}': { shape: 1, direction: 'right' },
    ']': { shape: 2, direction: 'right' },
    ')': { shape: 3, direction: 'right' },
  };

  const isMatch = (a, b) =>
    brackets[a].shape === brackets[b].shape &&
    brackets[a].direction === 'left' &&
    brackets[b].direction === 'right';

  const isSameLeftDirection = (a, b) =>
    brackets[a].direction === 'left' && brackets[b].direction === 'left';

  for (const bracket of s) {
    const lastBracket = stack[stack.length - 1];

    if (!lastBracket || isSameLeftDirection(lastBracket, bracket)) {
      stack.push(bracket);
      continue;
    }
    if (isMatch(lastBracket, bracket)) {
      stack.pop();
      continue;
    }
    return false;
  }

  return stack.length === 0 ? true : false;
};
