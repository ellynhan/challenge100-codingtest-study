//
//  1406.swift
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/14.
//

/*
 [Input]
 abcd
 3
 P x
 L
 P y
 [Output]
 abcdyx
 */
// 시간복잡도: O(n)
// 최악시간: 500,000
// 난이도: Silver 2
// Timer: 23m
// Url: https://www.acmicpc.net/problem/1406

import Foundation

// 입력
var leftStr = readLine()!
var rightStr = ""
let n = Int(readLine()!)!

// 풀이
for _ in 0..<n {
    let op = readLine()!
    
    switch op {
    case "L":
        if !leftStr.isEmpty {
            rightStr.append(leftStr.removeLast())
        }
    case "D":
        if !rightStr.isEmpty {
            leftStr.append(rightStr.removeLast())
        }
    case "B":
        if !leftStr.isEmpty {
            leftStr.removeLast()
        }
    default:
        leftStr.append(op.last!)
    }
}

// 출력
print(leftStr + rightStr.reversed())
