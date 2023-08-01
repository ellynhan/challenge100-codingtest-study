//
//  1475.swift
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/14.
//

/*
 [Input]
 9999
 [Output]
 2
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Silver 5
// Timer: 5m
// Url: https://www.acmicpc.net/problem/1475

import Foundation

var n: Int = Int(readLine()!)!
var ans: Int = 0
var arr: [Int] = [Int](repeating: 0, count: 10)

while n != 0 {
    arr[n % 10] += 1
    n /= 10
}

for i in 0..<10 {
    if i == 6 || i == 9 {
        continue
    }
    ans = max(ans, arr[i])
}

print(max(ans, (arr[6] + arr[9] + 1) / 2))
