/*

프로그래머스 / 올바른 괄호 / 레벨 2
https://programmers.co.kr/learn/courses/30/lessons/12909

< 소요 시간 >
50분

< 프로그래밍 계획 >

- 1차 시도
  1.  s의 첫 요소가 ')' 이면 false
  2.  s의 마지막 요소가 '(' 이면 false
  3.  s의 길이가 홀수면 false
  4.  s의 요소를 처음부터 체크
      요소가 '('면 스택에 넣음
      요소가 ')'이고 스택에 값이 있으면 스택.pop() or 스택에 값이 없으면 처음이 ')'게 되니까 false 리턴

- 2차 시도
  1.  스택에 쌓이는 개수를 count 변수로 관리
  2.  s의 요소를 처음부터 체크
      요소가 '(' 이면 count++ (올바른 괄호일 수 있음)
      요소가 ')' 인데 count가 0이면 return false (올바른 괄호일 수 없음)
      요소가 ')' 이면 count-- (기존에 있던 '('와 짝지어져서 없애버리기)
  3.  최종 count 값으로 결과 return

*/

// 2차 시도 - 통과
function solution(s) {
  let count = 0;
  const frontBracket = "(";

  for (const bracket of s) {
    if (bracket === frontBracket) {
      count++;
    } else {
      if (count === 0) return false;
      count--;
    }
  }

  return count ? false : true;
}

/* 

// 1차 시도 - 효율성 테스트 실패
function solution(s){
    if(s[0] === ')') return false;
    if(s[s.length - 1] === '(') return false;
    if(s.length % 2 !== 0) return false;
    
    const stack = [];
    
    for(const bracket of s){
        const lastBracket = stack[stack.length - 1];
        
        if (bracket === '(') {
            stack.push(bracket)
        } else {
            if (lastBracket === undefined) return false;
            stack.pop()
        };
    };
    
    return true;
}
*/
