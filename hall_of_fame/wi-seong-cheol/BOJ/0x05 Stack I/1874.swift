//
//  1874.swift
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/14.
//

/*
 [Input]
 8
 4
 3
 6
 8
 7
 5
 2
 1
 [Output]
 +
 +
 +
 +
 -
 -
 +
 +
 -
 +
 +
 -
 -
 -
 -
 -
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 2
// Timer: 34m
// Url: https://www.acmicpc.net/problem/1874

import Foundation

// 입력
let n: Int = Int(readLine()!)!
var S: [Int] = []
var ans: [String] = []
var cnt: Int = 1

// 풀이
for _ in 0 ..< n {
    let x: Int = Int(readLine()!)!
    while cnt <= x {
        S.append(cnt)
        ans.append("+")
        cnt += 1
    }
    if S.last == x {
        S.popLast()
        ans.append("-")
    } else {
        print("NO")
        exit(0)
    }
}

// 출력
print(ans.joined(separator: "\n"))
