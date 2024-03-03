/*
    LeetCode / Best Time to Buy and Sell Stock / Easy / 00:33:39
    https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


    ## Pseudo Code ##
    
    0. prices.length === 1 이면 return 0

    1. 변수설정
        ㄴ buy = Number.MAX_SAFE_INTEGER
        ㄴ profit = 0

    2. prices를 forEach로 반복
        ㄴ price가 buy보다 작으면 => buy를 price로 변경
        ㄴ price가 buy보다 크면
            ㄴ diff = price - buy
            ㄴ diff > profit => profit을 diff로 변경
        
        => 이중 if문 제거
          ㄴ diff = price - buy
          ㄴ diff < 0 => buy = price;
          ㄴ diff > profit => profit = diff;

    3. return profit
*/

var maxProfit = function (prices) {
  if (prices.length === 1) return 0;

  let buy = Number.MAX_SAFE_INTEGER;
  let profit = 0;

  prices.forEach(price => {
    const diff = price - buy;

    if (diff > profit) {
      profit = diff;
    } else if (diff < 0) {
      buy = price;
    }
  });

  return profit;
};
