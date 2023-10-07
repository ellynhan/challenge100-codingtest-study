

function solution(price, money, count) {
  let moneyRequired = 0;
  for(let i = 1; i <= count; i++){
    moneyRequired += price * i;
  }
 return  (money - moneyRequired) < 0 ?  Math.abs(money - moneyRequired) : 0
 
}
console.log(solution(3,40,4));

