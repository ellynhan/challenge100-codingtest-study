/*

    Programmers / [1차] 캐시 / Level 2 / 00:39:12
    https://school.programmers.co.kr/learn/courses/30/lessons/17680


    ## Pseudo Code ## 
    
    * 시간복잡도 : O(N * C)
      ㄴ N (cities)의 수 만큼 순회
      ㄴ C (index 찾기(findIndex) C + 데이터 삭제(shift or splice) C + 데이터 추가(push) + 1)

    * 공간복잡도 : O(C)
      ㄴ 캐시를 저장할 공간이 필요. casheSize의 최대범위가 C (30)

    - 캐시 교체 알고리즘은 LRU(Least Recently Used)를 사용한다.
      - LRU은 캐시를 교체할 때 가장 오래된 캐시를 지우는 방법이다.

    0. 예외처리 - casheSize가 0이면 => return cities * 5  
    1. cashes 만들기 []
    2. cities를 순회
      ㄴ cashes에 저장된 데이터가 없으면
        => cashes 사이즈가 꽉 차있으면 맨앞 데이터 삭제(제일 오래된)
        => 실행시간 + 5
      ㄴ cashes에 저장된 데이터가 있으면
        => cashes의 해당 데이터 삭제
        => 실행시간 + 1
      ㄴ cashes에 데이터 추가
    3. 실행시간 리턴

*/

function solution(cacheSize, cities) {
  if (cacheSize === 0) return cities.length * 5;

  let time = 0;
  const cashes = [];

  for (const city of cities) {
    const _city = city.toLowerCase();
    const index = cashes.findIndex(cash => cash === _city);
    if (index === -1) {
      cashes.length === cacheSize && cashes.shift();
      time += 5;
    } else {
      cashes.splice(index, 1);
      time++;
    }
    cashes.push(_city);
  }

  return time;
}
