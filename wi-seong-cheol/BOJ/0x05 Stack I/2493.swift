//
//  2493.swift
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/14.
//

/*
 [Input]
 5
 6 9 5 7 4
 [Output]
 0 0 2 2 4
 */
// 시간복잡도: O(n)
// 최악시간: 500,000
// 난이도: Gold 5
// Timer: 18m
// Url: https://www.acmicpc.net/problem/2493

import Foundation

// 입력
let n: Int = Int(readLine()!)!
let arr: [Int] = readLine()!.split(separator: " ").map {Int(String($0))!}

var stack = [Int]()
var ans = Array(repeating: 0, count: n)

// 풀이
for i in stride(from: n - 1, to: -1, by: -1) {
    while !stack.isEmpty, arr[i] > arr[stack.last!] {
        let idx = stack.removeLast()
        ans[idx] = i + 1
    }
    stack.append(i)
}

// 출력
print(ans.map{String($0)}.joined(separator: " "))
