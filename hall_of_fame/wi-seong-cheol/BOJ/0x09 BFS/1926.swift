//
//  1926.swift
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/24.
//

/*
 [Input]
 6 5
 1 1 0 1 1
 0 1 1 0 0
 0 0 0 0 0
 1 0 1 1 1
 0 0 1 1 1
 0 0 1 1 1
 [Output]
 4
 9
 */
// 시간복잡도: O(n * m)
// 최악시간: 250,000
// 난이도: Silver 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1926

import Foundation

// 변수 선언
var cnt = 0, mxSize = 0
var n = 0, m = 0
var board = [[Int]]()
let dx = [0, 1, 0, -1]
let dy = [1, 0, -1, 0]
var vis = Array(repeating: Array(repeating: false, count: 501), count: 501)

// 입력
let nm = readLine()!.split(separator: " ").map{Int(String($0))!}
(n, m) = (nm[0], nm[1])
for _ in 0..<n {
    board.append(readLine()!.split(separator: " ").map{Int(String($0))!})
}

// 풀이
func OOB(_ x: Int, _ y: Int) -> Bool {
    return x < 0 || x >= n || y < 0 || y >= m
}

func bfs(_ x: Int, _ y: Int) {
    var queue = [(Int, Int)]()
    queue.append((x, y))
    vis[x][y] = true
    var size = 0

    while !queue.isEmpty {
        let (x, y) = queue.removeFirst()
        size += 1
        for dir in 0..<4 {
            let nx = x + dx[dir]
            let ny = y + dy[dir]
            if OOB(nx, ny) || vis[nx][ny] == true { continue }
            if board[nx][ny] == 0 { continue }
            vis[nx][ny] = true
            queue.append((nx, ny))
        }
    }
    mxSize = max(mxSize, size)
}

// 출력
for i in 0..<n {
    for j in 0..<m {
        if board[i][j] == 1 && vis[i][j] == false {
            cnt += 1
            bfs(i, j)
        }
    }
}

print(cnt)
print(mxSize)
