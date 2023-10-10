function solution(s) {
  const index = Math.floor(s.length /2)
  if(s.length % 2 !== 0){
    return s[index]
  }else{
 
    return s[index - 1] + s[index]
  }
 
}

console.log(solution("qwer"));
