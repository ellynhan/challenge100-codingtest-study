//
//  3273.swift
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/14.
//

/*
 [Input]
 9
 5 12 7 10 9 1 2 3 11
 13
 [Output]
 3
 */
// 시간복잡도: O(n)
// 최악시간: 1000000
// 난이도: Silver 3
// Timer: 5m
// Url: https://www.acmicpc.net/problem/3273

import Foundation

let n: Int = Int(readLine()!)!
let arr: [Int] = readLine()!.split(separator: " ").map { Int(String($0))! }
let x: Int = Int(readLine()!)!

var check: [Int] = [Int](repeating: 0, count: 2000001)

for i in 0..<n {
    check[arr[i]] = 1
}

var ans: Int = 0
for i in 0..<(x + 1)/2 {
    if check[i] != 0 && check[x - i] != 0 {
        ans += 1
    }
}

print(ans)
