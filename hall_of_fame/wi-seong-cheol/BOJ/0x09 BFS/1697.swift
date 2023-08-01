//
//  1697.swift
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/14.
//

/*
 [Input]
 5 17
 [Output]
 4
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 1
// Timer: 17m
// Url: https://www.acmicpc.net/problem/1697

import Foundation

// 입력
let input: [Int] = readLine()!.split(separator: " ").map {Int(String($0))!}
let (n, m) = (input[0], input[1])

// 풀이
var Q: [Int] = []
var t: [Int] = [Int](repeating: -1, count: 100001)
t[n] = 0;
Q.append(n)

while t[m] == -1 {
    let cur = Q.first!
    Q.removeFirst()
    for nx in [cur-1, cur+1, 2*cur] {
        if OOB(nx) || t[nx] != -1 {
            continue
        }
        Q.append(nx)
        t[nx] = t[cur] + 1
    }
}

func OOB(_ x: Int) -> Bool {
    return x < 0 || x > 100000;
}

// 출력
print(t[m])
