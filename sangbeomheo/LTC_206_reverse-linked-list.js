/*

    LeetCode / Reverse Linked List / Easy / 00:35:24
    https://leetcode.com/problems/reverse-linked-list/


    ## Pseudo Code ##
    
    1. 노드의 위치를 변수로 설정
        ㄴ prev, curr, next

    2. while 반복문
        ㄴ curr이 노드일 경우 계속 반복
        
        ㄴ curr.next를 next에 할당
        ㄴ curr를 prev에 할당
        ㄴ next를 curr에 할당
        ㄴ 중간에 화살표가 안 끊어지게!

    3. prev를 리턴
        ㄴ while문이 종료가되면 curr는 null이 되고 prev가 head가 된다.
*/

var reverseList = function (head) {
  if (!head?.next) return head;

  let prev = null;
  let curr = head;
  let next = null;

  while (curr) {
    next = curr.next;
    curr.next = prev;
    prev = curr;
    curr = next;
  }

  return prev;
};
