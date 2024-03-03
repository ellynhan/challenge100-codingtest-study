// https://programmers.co.kr/learn/courses/30/lessons/42747

function solution(citations) {
  citations.sort((a, b) => b - a);

  for (let i = 0; i < citations.length; i++) {
    const citation = citations[i];
    const count = i;

    if (count >= citation) return count;
  }

  return citations.length;
}

console.log(solution([3, 0, 6, 1, 5])); // 3
console.log(solution([10, 10, 10, 10, 10])); // 5
console.log(solution([0, 0, 0, 0, 0])); // 0
console.log(solution([0, 0, 1, 0, 0])); // 1
console.log(solution([6, 5, 4, 3, 2, 1])); //
console.log(solution([22, 42])); // 2
