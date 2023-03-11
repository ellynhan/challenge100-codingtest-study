function solution(array) {
  // map 객체 사용하기
  let map = new Map();
  
  // 배열의 길이가 1일 경우는 곧바로 값을 반환   
  if (array.length === 1) {
    return array[0];
  }

  // map에 각 숫자가 몇 번 등장했는지 기록
  for (let i = 0; i < array.length; i++) {
    if (map.has(array[i])) {
      map.set(array[i], map.get(array[i]) + 1);
    } else {
      map.set(array[i], 1);
    }
  }
  
  // 등장 횟수가 가장 많은 숫자 찾기
  let maxCount = 0;
  let maxNum = [];
  map.forEach((count, num) => {
    if (count > maxCount) {
      maxCount = count;
      maxNum = [num];
    } else if (count === maxCount) {
      maxNum.push(num);
    }
  });

  // 최빈값이 여러 개면 -1 반환, 아니면 최빈값 반환
  if (maxNum.length > 1) {
    return -1;
  } else {
    return maxNum[0];
  }
}
