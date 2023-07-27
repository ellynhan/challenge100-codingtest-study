//
//  1158.swift
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/14.
//

/*
 [Input]
 7 3
 [Output]
 <3, 6, 2, 7, 5, 1, 4>
 */
// 시간복잡도: O(nk)
// 최악시간: 25000000
// 난이도: Silver 4
// Timer: 20m
// Url: https://www.acmicpc.net/problem/1158

import Foundation

// 입력
let nk: [Int] = readLine()!.split(separator: " ").map { Int(String($0))! }
let (n, k) = (nk[0], nk[1])

// 풀이
var arr = Array(1...n)
var idx = 0
var result = ""
while !arr.isEmpty {
    idx = (idx + k - 1) % arr.count
    let a = arr.remove(at: idx)
    result += "\(a), "
}
result.removeLast(2)

// 출력
print("<\(result)>")
