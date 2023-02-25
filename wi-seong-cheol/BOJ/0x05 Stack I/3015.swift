//
//  3015.swift
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/14.
//

/*
 [Input]
 7
 2
 4
 1
 2
 2
 5
 1
 [Output]
 10
 */
// 시간복잡도: O(n)
// 최악시간: 500,000
// 난이도: Platinum 1
// Timer: 19m
// Url: https://www.acmicpc.net/problem/3015

import Foundation

// 입력
let n = Int(readLine()!)!
var stack: [(Int, Int)] = []
var result = 0

// 풀이
for _ in 0 ..< n {
    let tall = Int(readLine()!)!
    var cnt = 1
    while !stack.isEmpty, stack.last!.0 <= tall {
        result += stack.last!.1
        if stack.last!.0 == tall {
            cnt += stack.last!.1
        }
        stack.removeLast()
    }
    if(!stack.isEmpty) {
        result += 1
    }
    stack.append((tall, cnt))
}

// 출력
print(result)
