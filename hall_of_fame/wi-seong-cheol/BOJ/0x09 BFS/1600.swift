//
//  1600.swift
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/24.
//

/*
 [Input]
 1
 4 4
 0 0 0 0
 1 0 0 0
 0 0 1 0
 0 1 0 0
 [Output]
 4
 */
// 시간복잡도: O(n * m)
// 최악시간: 20,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1600

import Foundation

// 변수 선언
var k = 0, w = 0, h = 0
var board = [[Int]]()
var dx = [-1, 1, 0, 0]
var dy = [0, 0, -1, 1]
var horseDx = [-2, -1, -2, -1, 1, 2, 2, 1]
var horseDy = [-1, -2, 1, 2, -2, -1, 1, 2]

// 입력
k = Int(String(readLine()!))!
let wh = readLine()!.split(separator: " ").map{Int(String($0))!}
(w, h) = (wh[0], wh[1])
for _ in 0..<h{
    board.append(readLine()!.split(separator: " ").map{Int(String($0))!})
}

// 풀이
func OOB(_ x: Int, _ y: Int) -> Bool {
    return x < 0 || x >= h || y < 0 || y >= w
}

func bfs() -> Int{
    var queue = [(Int, Int, Int, Int)]()//x, y, 이동횟수, k
    var visited = Array(repeating: Array(repeating: Array(repeating: false, count: 31), count: 201), count: 201)
    queue.append((0, 0, 0, k))
    visited[0][0][k] = true
    var result = -1
    var idx = 0
    while queue.count > idx{
        let (x, y, move, k) = queue[idx]
        idx += 1
        if x == h - 1 && y == w - 1 {
            result = move
            break
        }

        if k > 0 {
            for i in 0..<8{
                let nx = horseDx[i] + x
                let ny = horseDy[i] + y

                if OOB(nx, ny) { continue }
                if board[nx][ny] == 1 || visited[nx][ny][k - 1] { continue }
                queue.append((nx, ny, move + 1, k - 1))
                visited[nx][ny][k - 1] = true
            }
        }
        for i in 0..<4{
            let nx = x + dx[i]
            let ny = y + dy[i]
            if OOB(nx, ny) { continue }
            if board[nx][ny] == 1 || visited[nx][ny][k] { continue }
            queue.append((nx, ny, move + 1, k))
            visited[nx][ny][k] = true
        }


    }
    return result
}

// 출력
print(bfs())
