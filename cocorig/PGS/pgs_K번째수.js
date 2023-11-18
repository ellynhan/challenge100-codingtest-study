// 1.[i, j, k]를 원소로 가진 2차원 배열 commands배열을 순회하면서 각 command 배열을 구조분해할당으로 [i, j, k]나눠줍니다.
// 2. array 배열에서 i부터 j까지의 부분 배열을 slice를 사용하여 잘라내고, 정렬해줍니다.
// 3. 정렬된 배열에서 k번째 숫자를 찾아 반환합니다.

function solution(array, commands) {
  return commands.map((command) => {
    const [start, end, k] = command;
    const sortedArr = array.slice(start - 1, end).sort((a, b) => a - b);
    return sortedArr[k - 1];
  });
}
