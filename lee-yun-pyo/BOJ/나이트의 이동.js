const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const input = fs
  .readFileSync(filePath)
  .toString()
  .split("\n")
  .map((v) => v.trim());

const T = +input[0]; // 테스트케이스 개수
let start = 1;

// 8방향 설정
const dx = [1, 1, 2, 2, -1, -1, -2, -2];
const dy = [2, -2, 1, -1, 2, -2, 1, -1];

for (let i = 0; i < T; i++) {
  const length = +input[start];
  const [startX, startY] = input[start + 1].split(" ").map((v) => +v);
  const [destX, destY] = input[start + 2].split(" ").map((v) => +v);

  // 그래프 생성
  let [graph, sub] = [[], []];
  for (let i = 0; i < length; i++) {
    for (let j = 0; j < length; j++) {
      sub.push(0);
    }
    graph.push(sub);
    sub = [];
  }

  // BFS 탐색
  function bfs(startX, startY, destX, destY) {
    if (startX === destX && startY === destY) return 0;
    let queue = [[startX, startY]];
    while (queue.length !== 0) {
      const [x, y] = queue.shift();
      for (let i = 0; i < 8; i++) {
        const nx = x + dx[i];
        const ny = y + dy[i];
        if (nx >= length || nx < 0 || ny >= length || ny < 0) continue;
        if (graph[nx][ny] !== 0) continue;
        if (graph[nx][ny] === 0) {
          graph[nx][ny] = graph[x][y] + 1;
          queue.push([nx, ny]);
        }
      }
    }
    return graph[destX][destY];
  }
  console.log(bfs(startX, startY, destX, destY));

  start += 3;
}
