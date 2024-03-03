// 아래와 같은 결과를 출력하는 function을 구현하라

// bool OneEditApart(string s1, string s2)

// OneEditApart("cat", "dog") = false 
// OneEditApart("cat", "cats") = true 
// OneEditApart("cat", "cut") = true 
// OneEditApart("cat", "cast") = true 
// OneEditApart("cat", "at") = true
// OneEditApart("cat", "acts") = false 
// 한개의 문자를 삽입, 제거, 변환을 했을때 s1, s2가 동일한지를 판별하는 OneEditApart 함수를 작성하시오.



function OneEditApart(s1,s2){

  while(s1.length != 0 && s2.length != 0){
    if(s1.slice(-1) === s2.slice(-1)){ // 마지막 문자 비교
      s1 = s1.slice(0,-1) //0부터 마지막 원소 전까지 자르기
      s2 = s2.slice(0,-1)
    }else if(s1[0] ===  s2[0]){ // 첫 번째 문자 비교
      s1 = s1.slice(1)
      s2 = s2.slice(1)
    }
    else{
      break;
    }
  }
  return s1.length <= 1 && s2.length <= 1; // 불린값으로 반환
}

console.log(OneEditApart("cat", "cast"));