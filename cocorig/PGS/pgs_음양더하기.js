function solution(absolutes, signs) {
  let sum = 0;
  for(let i = 0; i < absolutes.length; i++) {
    if(!signs[i]){
      sum -= absolutes[i];
    }else{
      sum += absolutes[i];
    }
  }
  return sum;
}

console.log(solution([1,2,3] ,[false,false,true]));