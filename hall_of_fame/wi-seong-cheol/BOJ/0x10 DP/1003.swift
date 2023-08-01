//
//  1003.swift
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/15.
//

/*
 [Input]
 3
 0
 1
 3
 [Output]
 1 0
 0 1
 1 2
 */
// 시간복잡도: O(n)
// 최악시간: 40
// 난이도: Silver 3
// Timer: 7m
// Url: https://www.acmicpc.net/problem/1003

import Foundation

// 입력
let t = Int(readLine()!)!
var d = [[Int]](repeating: [Int](repeating: 0, count: 2), count: 41)

// 풀이
d[0][0] = 1
d[1][1] = 1
for i in 2 ... 40 {
    d[i][0] = d[i - 1][0] + d[i - 2][0]
    d[i][1] = d[i - 1][1] + d[i - 2][1]
}

// 출력
for _ in 0..<t {
    let n = Int(readLine()!)!
    print("\(d[n][0]) \(d[n][1])")
}
