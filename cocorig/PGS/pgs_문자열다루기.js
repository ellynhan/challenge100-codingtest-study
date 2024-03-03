function solution(s) {
  const regExp = /[a-zA-Z]/g; //  숫자로만 구성

  if((s.length ===  4 || 6) ){
      return true;
  }else{
      return false;
  }
}
console.log(solution("13"));

// x || y 
// x가 참이면  x || y 는 참이된다. y의 값은 확인하지 않는다.
// 만약 x가 거짓이고 , y가 참이면 x || y 는 참이된다.

// s.length === 4 || 6
// s.length === 4 이 참인경우 전체 조건이 참 , 뒤엔 확인하지 않는다.
// s.length === 4 이 거짓인경우 6이 참인 경우 .전체 조건은 참이 된다.

/// s.length === 4 || 6 이건 앞에께 참이든 거짓이든 다 true를 반환하게 된다.
//  그 이유는 내 의도대로 s.length === 6 조건을 를 확인하는게 아니라 숫자 리터럴로 간주되기 때문에  참(true) 간주된다.
// 0을 제외한 모든 숫자는 조건식에서 "참"