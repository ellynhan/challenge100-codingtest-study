function solution(lines) {

  let line = new Array(200).fill(0);
  let ans = 0;
  for(let i = 0; i < lines.length; i++){
    // [0,1]
    for(let j = lines[i][0] + 100; j < lines[i][1] + 100; j++){
      line[j]++;
    }
  }
  for(let i = 0; i < 200; i++){
    if(line[i] > 1){
      ans++;
    }
  }
  return ans;
}

console.log(solution([[0, 1], [2, 5], [3, 9]]));