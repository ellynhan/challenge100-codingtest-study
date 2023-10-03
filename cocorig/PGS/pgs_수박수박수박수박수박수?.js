function solution(n) {
  let ans = '';
  for(let i = 0; i < n; i++) {
    if(ans.length % 2 !== 0){
      ans += '박'
    }else{
      ans += '수'
    }
  }
  return ans;
}

console.log(solution(3));