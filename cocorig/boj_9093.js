const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';
let input = fs.readFileSync(filePath).toString().split('\n');

const iter =  input.shift(); //2

for(let i = 0; i < iter; i++){
  let words = input[i].split(' ');
  let ans =  words.map((word)=>
      word.split('').reverse().join('')
  )
  console.log(ans.join(' '));

}
