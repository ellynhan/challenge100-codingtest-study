// 1. 문자열은 하나 이상의 공백문자로 구분되어있기 때문에 먼저 공백을 기준으로 나눠줍니다.
// 2. 각 단어마다 문자를 하나씩 확인하면서 인덱스 기준으로 짝수인지 홀수인지 구분합니다.
// 3. 짝수 번째 문자면 대문자, 홀수 번째 문자면 소문자로 변환해줍니다.
// 4. 각 단어를 변환한 후 , 다시 하나의 문자열로 합쳐 결과를 반환합니다.

function solution(s) {
  return s
    .split(" ") // [try, hello,world]
    .map(
      (word) =>
        word
          .split("") // [t ,r, y]
          .map(
            (
              char,
              index // (t , 0)  (r , 1)  (y , 2)
            ) => (index % 2 === 0 ? char.toUpperCase() : char.toLowerCase())
          )
          .join("") //  'TrY' 처리한 문자를 다시 한 문자열로 조합
    ) // [TrY ,HeLlO ,WoRlD]
    .join(" "); // "TrY HeLlO WoRlD"
}
const result = solution("try hello world");
console.log(result);
