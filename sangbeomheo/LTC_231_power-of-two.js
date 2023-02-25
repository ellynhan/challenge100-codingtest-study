/*

    LeetCode / Power of Two / Easy / 00:33:52
    https://leetcode.com/problems/power-of-two/


    ## Pseudo Code ##

    재귀로 풀어보자!

*/

// 재귀 2차 풀이
var isPowerOfTwo = function (n) {
  if (n === 0) return false;
  if (n === 1) return true;
  if (n % 2 !== 0) return false;
  return isPowerOfTwo(n / 2);
};

// 반복문 풀이
// var isPowerOfTwo = function (n) {
//   if (n === 0) return false;

//   while (true) {
//     if (n === 1) return true;
//     if (n % 2 !== 0) return false;
//     n = n / 2;
//   }
// };

// 재귀 1차 풀이
// var isPowerOfTwo = function (n) {
//   if (n <= 0) return false;
//   if (n === 1) return true;

//   let value = true;

//   const divideByTwo = number => {
//     if (number % 2 !== 0) {
//       bool = false;
//     } else if (Math.abs(number) > 2) {
//       divideByTwo(number / 2);
//     }
//   };

//   divideByTwo(n);

//   return value;
// };
