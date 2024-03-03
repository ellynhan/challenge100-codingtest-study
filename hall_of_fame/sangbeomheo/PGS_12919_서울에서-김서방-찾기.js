/*

프로그래머스 / 서울에서 김서방 찾기 / 레벨 1
https://school.programmers.co.kr/learn/courses/30/lessons/12919

< 소요 시간 >
11분

<프로그래밍 계획>
  - indexOf()!!!
*/

function solution(seoul) {
  return `김서방은 ${seoul.indexOf("Kim")}에 있다`;

  /*
    
    let position;
    seoul.some((name, index) => {
        position = index;
        return name === 'Kim';
    });
    return `김서방은 ${position}에 있다`;
    
    */
}
