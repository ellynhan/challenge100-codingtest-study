var isPalindrome = function (x) {
  // 뒤집어도 같을 때 true
  // 뒤집어서 나열해주는 함수가 뭐가 있지?
  let xx = x.toString(); // 문자열화
  let y = xx.split("").reverse().join(""); // 뒤집기

  if (xx === y) {
    //비교
    return true;
  }
  return false;
};
