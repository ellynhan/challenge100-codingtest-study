// https://programmers.co.kr/learn/courses/30/lessons/42576

function solution(participant, completion) {
  const hash = {};
  participant.forEach((player) =>
    hash[player] ? hash[player]++ : (hash[player] = 1)
  );
  completion.forEach((player) => hash[player]--);

  for (let name in hash) {
    if (hash[name] === 1) return name;
  }
}

console.log(solution(["leo", "kiki", "eden"], ["eden", "kiki"])); // "leo"
console.log(
  solution(["mislav", "stanko", "mislav", "ana"], ["stanko", "ana", "mislav"])
); // "mislav"
console.log(
  solution(
    ["marina", "josipa", "nikola", "vinko", "filipa"],
    ["josipa", "filipa", "marina", "nikola"]
  )
); // "vinko"

/**
 * [시도 1]
 * 1. 참가자들을 한 명씩 순회한다.
 * 2. 완주자들을 순회하면서 해당 참가자가 완주자 명단에 있는지 확인한다.
 * 4-1. 완주자 명단에 있다면 -> 완주자 명단에서 해당 참가자를 지운다.
 * 4-2. 완주자 명단에 없다면 -> 완주하지 못한 1인이기 때문에 반복문을 종료하고 값을 리턴한다.
 *
 *   let answer = "";
 *   participant.some((p) => {
 *     const index = completion.findIndex((c) => c === p);
 *     if (index === -1) {
 *       answer = p;
 *       return true;
 *     }
 *     completion.splice(index, 1);
 *   });
 *   return answer;
 *
 * 위의 방식으로 시도했을 때, 효율성 테스트를 모두 실패함. 아마도 시간복잡도가 O(n2)이라서 그런 듯.. 해시로 풀어야할 것 같다.
 *
 * [시도 2]
 * 1. 객체를 생성
 * 2. 참가자들을 전부 객체에 넣는다. 참가자(키): 1(벨류)
 * 3. 완주자들을 하나씩 객체에서 찾아 벨류를 -1 한다.
 * 4. 객체 중에 벨류가 1인 키를 찾아 리턴한다.
 *
 *
 */
