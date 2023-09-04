// 문제 설명

// 1차원의 점들이 주어졌을 때, 그 중 가장 거리가 짧은 것의 쌍을 출력하는 함수를 작성하시오. (단 점들의 배열은 모두 정렬되어있다고 가정한다.)

// 예를들어 S={1, 3, 4, 8, 13, 17, 20} 이 주어졌다면, 결과값은 (3, 4)가 될 것이다.

function solution(){
   // 제일 큰 범위로 설정
    let min = Number.MAX_SAFE_INTEGER;
    let idx = 0;
    const s = [1, 3, 4, 8, 13, 17, 20];

    for(let i = 1; i < s.length; i++){
    
      if(s[i] - s[i - 1] < min){

        idx = i;
        min =  s[i] - s[i - 1];
        // console.log(s[i], s[i - 1]);
        // console.log(idx); //2 
      }
    
    }
    return `${s[idx]}, ${s[idx -1 ]}`;
    // console.log(idx);
}

console.log(solution());

