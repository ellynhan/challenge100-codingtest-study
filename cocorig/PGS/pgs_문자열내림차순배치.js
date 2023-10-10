function solution(s) {

  const ans = s.split('').sort((a,b)=>{
    const charA = a.charCodeAt(0)
    const charB = b.charCodeAt(0)
    return charB - charA;
  })
  return ans.join('');
  

}
console.log(solution("Zbcdefg"));
