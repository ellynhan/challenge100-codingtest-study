//다음과 같은 형태의 배열을

// [a1,a2,a3...,an,b1,b2...bn]

// 다음과 같은 형태로 바꾸시오

// [a1,b1,a2,b2.....an,bn]
// 입력을 저장하는 저장소 이외에 추가적인 저장장소를 사용치 않는다는게 제약조건입니다
// 제약 조건에 따라 추가 저장 공간을 사용하지 않고 원래의 배열을 수정함.

// 입력
const arr = ['a1', 'a2', 'a3', 'b1', 'b2', 'b3'];


function solution(arr) {

  const ans = [];
  const n = arr.length / 2;  // 3

  for (let i = 0; i < n; i++) {
    ans.push(arr[i], arr[i + n]);
  }

  return ans;
}

// 출력 
console.log(solution(arr));
//[ 'a1', 'b1', 'a2', 'b2', 'a3', 'b3' ]