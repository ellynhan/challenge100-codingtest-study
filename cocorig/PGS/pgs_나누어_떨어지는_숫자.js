function solution(arr, divisor) {

  //  먼저 나누어 떨어지는 원소를 걸러냄
  const divisibleNumbers = arr.filter((v)=> v % divisor === 0)
  // 오름차순으로 정렬한 배열을 반환
  if(divisibleNumbers.length === 0){
    return  [-1];
  }
  return divisibleNumbers.sort((a,b)=> a - b);
}

console.log(solution([3,2,6]	,10));

// [5, 10]