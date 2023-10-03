
function solution(arr1, arr2) {
  const answer = [];
  
  for(let i=0; i<arr1.length; i++){ // 두 배열의 길이는 같으니까 arr1를 기준으로 배열 길이만큼 반복한다. -> 배열의 길이는 2 , i=0,i=1
      let sum = []; 

      for(let j=0; j<arr1[i].length; j++){ //arr1 안의 원소의 길이를 만큼 각각 더해줘야 하기 때문에 arr1[i]로 기준을 잡는다. (행과 열의 크기가 같으니까)

        //  여기서 바로 더해줘서 sum 배열에 넣어준다.
          sum.push(arr1[i][j] + arr2[i][j])
        
      }
      answer.push(sum) // sum = [4,6],[7,9]
  }
  return answer;
}                     
// console.log(solution([[1,2],[2,3]],[[3,4],[5,6]]));

// 코드 리팩토링

function solution(arr1, arr2) {
  return arr1.map((row, i) => 
  // 1. row = [ 1, 2 ] ,i =  0
//   2. row = [ 2, 3 ] ,i =  1
  row.map((v , j)=> v + arr2[i][j])
);
}

console.log(solution([[1,2],[2,3]],[[3,4],[5,6]]));
[ 1, 2 ].map((v, i) =>console.log(v, i))

