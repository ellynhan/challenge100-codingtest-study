/*

프로그래머스 / 스킬트리 / 레벨 2
https://school.programmers.co.kr/learn/courses/30/lessons/49993

< 소요 시간 >
19분

<프로그래밍 계획>
  - skill_trees의 tree 요소를 하나씩 체크
    - skill에 없는거면 통과
    - skill에 있는데 순서가 맞으면 통과
      - skill에서 해당 순서 요소 제거
    - skill에 있는데 순서가 안맞으면 실패 break

  - skill을 reverse해서 스택으로 만들어 처리 pop()
*/

function solution(skill, skill_trees) {
  let possibleTrees = 0;

  skill_trees
    .map((str) => [...str])
    .forEach((tree) => {
      const skillStack = [...skill].reverse();
      let isPossible = true;

      for (const single of tree) {
        if (!skillStack.includes(single)) continue;
        if (single == skillStack[skillStack.length - 1]) {
          skillStack.pop();
          continue;
        }
        isPossible = false;
        break;
      }

      isPossible && possibleTrees++;
    });

  return possibleTrees;
}
