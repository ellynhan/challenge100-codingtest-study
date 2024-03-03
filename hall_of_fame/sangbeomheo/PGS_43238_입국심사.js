/*

    프로그래머스 / 입국심사 / 레벨 3 / 00:38:47
    https://school.programmers.co.kr/learn/courses/30/lessons/43238


    ## Pseudo Code ##
    
    - 이진탐색으로 구해보자.
    - 모든 사람이 심사를 받는데 걸리는 예상최소시간 & 최대시간을 구하고 중간값부터 이진탐색으로 찾는다.
    - 중간값(시간)이 소요됐을 때 처리가능한 사람 수를 구해서 그 실제 사람수보다
        ㄴ 많으면 더 적은 시간으로 처리할 수 있는 것 : 중간값이 더 작아야함
        ㄴ 적으면 더 많은 시간으로 처리할 수 있는 것 : 중간값이 더 커야함
    - 이진탐색으로 전체를 돌고 나온 최소시간을 리턴
        ㄴ 중간에 찾았다고 바로 리턴하면 안된다. 처리가능한 사람 수와 실제 사람 수가 일치하더라도 시간이 차이가 날 수 있음

    
    1. 모든 사람이 심사를 받는데 걸리는 임의의 최소 시간, 최대 시간, 후보 시간 구하기
        ㄴ fastest : 1 (제한 사항에 n 최소 1명, 심사관 최소 1, 걸리는 시간 최소 1)
        ㄴ slowest : times 중 가장 높은 시간 * n (가장 오래걸리는 심사관한테 전부 받는 경우)
        ㄴ candidate : fastest와 slowest 사이의 정수인 중간 값

    2. while 반복문
        ㄴ 조건 : fastest <= slowest 

        ㄴ candidate로 심사받을 수 있는 사람 수 judged 구하기
        
        ㄴ judged와 n을 비교
          ㄴ judged가 n보다 크면 => 더 적은 시간으로 처리가능하니까 slowest = candidate - 1
          ㄴ judged가 n보다 작거나 같으면 => 더 많은 시간이 필요하니까 fastest = candidate + 1

    3. candidate 리턴

*/

function solution(n, times) {
  let fastest = Math.min(...times) * 1;
  let slowest = Math.max(...times) * n;
  let candidate = Math.floor((fastest + slowest) / 2);

  while (fastest <= slowest) {
    const judged = times.reduce((sum, time) => sum + Math.floor(candidate / time), 0);

    if (judged < n) {
      fastest = candidate + 1;
    } else {
      slowest = candidate - 1;
    }

    candidate = Math.floor((fastest + slowest) / 2);
  }

  return fastest;
}
