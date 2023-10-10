// 아마존 면접문제

// A사무실에는 특정일자의 출퇴근 시간이 기록된 거대한 로그파일이 있다고 한다.

// 파일의 형식은 다음과 같다. (한 라인에서 앞부분은 출근시간(HH:MM:SS), 뒷부분은 퇴근시간이다)

// 09:12:23 11:14:35
// 10:34:01 13:23:40
// 10:34:31 11:20:10
// 특정시간을 입력(예:11:05:20)으로 주었을 때 그 시간에 총 몇 명이 사무실에 있었는지 알려주는 함수를 작성하시오.

const logs = [
  '09:12:23 11:14:35',
  '10:34:01 13:23:40',
  '10:34:31 11:20:10'
]
// 출근시간,퇴근시간으로 나눠서 입력 시간과 비교한다.
const inputTime = '11:05:20';

function solution(logs,inputTime){
  let cnt = 0;
  let t = inputTime.split(':').join('')

  for(let i = 0; i < logs.length; i++){
    
  const str =  logs[i].split(':').join('')
  const 출근 = str.split(' ')[0];
  const 퇴근 =  str.split(' ')[1];
    
  if(출근 <= t && t <= 퇴근){
    
        cnt++;
    }
  }
  return cnt;
}


console.log(solution(logs, inputTime));

// if('091223' <= '110520'<= '111435'){
//   console.log('dd');
// }