//
//  두 큐 합 같게 만들기.swift
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/16.
//

// 시간복잡도: O(n)
// 최악시간: 600,000
// 난이도: Level 2
// Timer: 32m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/118667?language=swift

import Foundation

func solution(_ queue1:[Int], _ queue2:[Int]) -> Int {
    var q1 = queue1
    var q2 = queue2
    var sum1 = q1.reduce(0, +)
    var sum2 = q2.reduce(0, +)
    var pointer1 = 0
    var pointer2 = 0
    for i in 0..<600010 {
        if sum1 == sum2 {
            return i
        }
        if sum1 < sum2 {
            q1.append(q2[pointer2])
            sum1 += q2[pointer2]
            sum2 -= q2[pointer2]
            pointer2 += 1
        } else {
            q2.append(q1[pointer1])
            sum2 += q1[pointer1]
            sum1 -= q1[pointer1]
            pointer1 += 1
        }
    }
    return -1
}
