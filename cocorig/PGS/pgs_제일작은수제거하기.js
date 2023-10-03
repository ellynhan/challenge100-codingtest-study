function solution(arr) {
  if(arr.length <= 1) {
    return [-1];
  }
  let min = Math.max(...arr);

  for(let i = 0; i < arr.length; i++) {
    if(arr[i] < min) {
      min = arr[i];
    }
  }
  const ans =  arr.filter((item ,  index)=> item !== min)
  return ans;
}
console.log(solution([4,3,2,1]));
