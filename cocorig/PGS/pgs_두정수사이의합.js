// function solution(a, b) {
//   let ans = 0;
//   if(a < b){
//     for(let i = a;  i <= b; i++) {
//       ans += i;
//     }
//     return ans;
//   }else if(a > b){
//     for(let i = b;  i <= a; i++) {
//       ans += i;
//     }
//     return ans;
//   }else{
//     return a;
//   }

// }

function solution(a, b) {

  let sum = 0;
  if(a === b){
    return a;
  }
  const [min, max] = [Math.min(a, b), Math.max(a, b)];

  for(let i = min; i <= max; i++){
    sum += i;
  }
  return sum;
}

console.log(solution(3, 5));